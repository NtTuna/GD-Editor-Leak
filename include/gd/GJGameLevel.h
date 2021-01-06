#pragma once

#include "CCLayer.h"

class GJGameLevel : public cocos2d::CCNode 
{
public:
    uint32_t _pad0[ 3 ];
    std::string* lastBuildSave_;
    int levelIDRand_;
    int levelIDSeed_;
    int levelID_;
    std::string* levelName_;
    std::string* levelDesc_;
    std::string* levelString_; // 0x110
    std::string* userName_;
    std::string* recordString_;
    int dword11C;
    int dword120;
    int dword124;
    int UIDRand_;
    int UIDSeed_;
    int userID_;
    int accIDRand_;
    int accIDSeed_;
    int accountID_;
    int difficulty_;
    int audioTrack_;
    int songID_;
    int levelRev_;
    bool byte150;
    bool byte151;
    int objCountRand_;
    int objCountSeed_;
    int objectCount_;
    int dword160;
    int ratings_;
    int ratingsSum_;
    int downloads_;
    bool isEditable_;
    bool byte171;
    bool byte172;
    int dword174;
    int dword178;
    bool byte17C;
    bool byte17D;
    bool byte17E;
    bool byte17F;
    int isVerRand_;
    int isVerSeed_;
    bool isVerified_;
    bool isUploaded_;
    bool hasBeenModified_;
    int levelVersion_;
    int gameVersion_;
    int attemptRand_;
    int attemptSeed_;
    int attempts_;
    int jumpsRand_;
    int jumpsSeed_;
    int jumps_;
    int clicksRand_;
    int clicksSeed_;
    int clicks_;
    int attTimeRand_;
    int attTimeSeed_;
    int attemptTime_;
    int gap1C4;
    bool byte1C8;
    bool byte1C9;
    int normalPercent_;
    int normPercentSeed_;
    int normPercentRand_;
    int newNormPercentRand_;
    int newNormPercentSeed_;
    int newNormalPercent_;
    int newNormPercent2Rand_;
    int newNormPercent2Seed_;
    int newNormalPercent2_;
    int practicePercent_;
    int likes_;
    int dislikes_;
    int levelLength_;
    int featured_; // 0x200
    int epic_; // 0x204
    bool byte208;
    int dword20C;
    int dailyIDRand_;
    int dailyIDSeed_;
    int dailyID_;
    int demonRand_;
    int demonSeed_;
    int demon_;
    int dword228;
    int starsRand_;
    int starsSeed_;
    int stars_;
    bool autoLevel_;
    int coins_;
    int coinsVerRand_;
    int coinsVerSeed_;
    int coinsVerified_;
    int passwordRand_;
    int passwordSeed_;
    int oriLevelRand_;
    int oriLevelSeed_;
    int originalLevel_;
    bool twoPlayerMode_;
    int failedPasswordAttempts_;
    int coin1VerifiedRand_;
    int coin1VerifiedSeed_;
    int coin1Verified_;
    int coin2VerfiiedRand_;
    int coin2VerifiedSeed_;
    int coin2Verified_;
    int coin3VerifiedRand_;
    int coin3VerifiedSeed_;
    int coin3Verified_;
    int requestedStars_;
    bool showedStarWarning_;
    int starRatings_;
    int starRatingsSum_;
    int maxStarRatings_;
    int minStarRatings_;
    int demonVotes_;
    int rateStars_;
    bool rateFeature_;
    int rateUser_;
    bool dontSave_;
    bool isHidden_;
    int requiredCoins_;
    bool isUnlocked_;
    cocos2d::CCPoint *lastCameraPos_;
    bool gap2C4[4];
    int lastEditorZoom_;
    int lastBuildTab_;
    int lastBuildPage_;
    int lastBuildGroupID_;
    int levelType_;
    int M_ID;
    int dword2E0;
    std::string* capacityString;
    bool byte2E8;
    bool byte2E9;
    int dword2EC;
    int dword2F0;
    
public:
    GJGameLevel();
    virtual ~GJGameLevel();

    static GJGameLevel* create( );

    std::string getAudioFileName( );                                                                                                
};