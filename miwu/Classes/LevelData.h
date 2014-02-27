//
//
//  LevelData.h
//  miwu
//
//  Created by wwm on 13-10-20.
//
//

#ifndef __MIWU__LevelData__
#define __MIWU__LevelData__

#include "cocos2d.h"
#define LEVEL_DATA_STRING(key) LevelData::sharedLevelData()->stringFromKey(key)
#define LEVEL_DATA_INT(key) LevelData::sharedLevelData()->intFromKey(key)
#define LEVEL_DATA_FLOAT(key) LevelData::sharedLevelData()->floatFromKey(key)
#define LEVEL_DATA_BOOLEAN(key) LevelData::sharedLevelData()->booleanFromKey(key)
#define LEVEL_DATA_POINT(key) LevelData::sharedLevelData()->pointFromKey(key)
#define LEVEL_DATA_RECT(key) LevelData::sharedLevelData()->rectFromKey(key)
#define LEVEL_DATA_SIZE(key) LevelData::sharedLevelData()->sizeFromKey(key)
#define LEVEL_DATA_ARRAY(key) LevelData::sharedLevelData()->arrayFromKey(key)
#define LEVEL_DATA_DICT(key) LevelData::sharedLevelData()->dictFromKey(key)

class LevelData : public cocos2d::CCObject
{
public:    
    static LevelData* sharedLevelData();

    /**
     *	@brief	 外部访问接口
     *
     *	@param 	key 	对应的level_data.plist中的Key
     *
     *	@return	对应的Value
     */
    const char* stringFromKey(std::string key);
    int intFromKey(std::string key);
    float floatFromKey(std::string key);
    bool booleanFromKey(std::string key);
    cocos2d::CCPoint pointFromKey(std::string key);
    cocos2d::CCRect rectFromKey(std::string key);
    cocos2d::CCSize sizeFromKey(std::string key);
    cocos2d::CCArray* arrayFromKey(std::string key);
    cocos2d::CCDictionary* dictFromKey(std::string key);

    /**
     *	@brief	 内存不足时调用
     */
    void purge();
    
    CC_SYNTHESIZE_READONLY(std::string, _levelDataPath, LevelDataPath);

protected:
    cocos2d::CCDictionary* _dictionary;
private:
    LevelData();
    ~LevelData();
    bool init();
};
#endif /* defined(__FishingJoy__LevelData__) */
