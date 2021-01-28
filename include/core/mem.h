#pragma once

#include <cstdint>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <array>
#include <initializer_list>

#include <dlfcn.h>
#include <cstring>


namespace saber::core::vm 
{
    struct traps 
    {
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_X86      = { 0xCD, 0x03 };                   // int 3
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_X86_2    = { 0x0F, 0x0B };                   // UD2

        static constexpr std::array<std::uint8_t, 4> TRAP_DATA_ARM      = { 0xF1, 0x00, 0xF0, 0xE7 };       // UDF #1
        static constexpr std::array<std::uint8_t, 2> TRAP_DATA_THUMB    = { 0xFE, 0xDE };                    // UDF #FDEE

        static constexpr std::array<std::uint8_t, 4> TRAP_DATA_ARM_THUMB    = { 0xfe, 0xde, 0xff, 0xe7 };   // UDF #FDEE
    };

#ifndef PAGE_SIZE
    static constexpr std::size_t PAGE_SIZE = 0x1000;
#endif

    static constexpr auto PAGE_START = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( ~( PAGE_SIZE - 1 ) & (addr) ); };
    static constexpr auto SET_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr | 1 ); };
    static constexpr auto CLEAR_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr & 0xFFFFFFFE ); };
    static constexpr auto TEST_BIT0 = []( const std::uintptr_t addr ) -> std::uintptr_t { return ( addr & 1 ); };

    template <std::size_t N>
    void write( const std::uintptr_t address, const std::array<uint8_t, N> bytes )
    {
        mprotect( 
            reinterpret_cast<void*>( PAGE_START( CLEAR_BIT0( address ) ) ),
            PAGE_SIZE * 2,
            PROT_READ | PROT_WRITE | PROT_EXEC
         );
        
        if ( TEST_BIT0( address ) )
            std::memcpy( (void*) CLEAR_BIT0( address ), (void*) bytes.data(), bytes.size() );
        else 
            std::memcpy( (void*) address, (void*) bytes.data(), bytes.size() );

        mprotect( 
            reinterpret_cast<void*>( PAGE_START( CLEAR_BIT0( address ) ) ),
            PAGE_SIZE * 2,
            PROT_READ | PROT_EXEC
         );

        cacheflush( CLEAR_BIT0( address ), CLEAR_BIT0(address) + bytes.size(), 0 );
    }

    std::uintptr_t get_proc_addr( const char* lib, const char* sym )
    {
        void* handle = dlopen( lib, RTLD_LAZY );
        if( handle == nullptr )
            return 0;

        return reinterpret_cast< std::uintptr_t >( dlsym( handle, sym ) );
    }
}