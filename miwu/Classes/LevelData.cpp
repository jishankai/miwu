//
//
//  LevelData.cpp
//  miwu
//
//  Created by wwm on 13-10-20.
//
//

#include "LevelData.h"
USING_NS_CC;
using namespace std;

#define LEVEL_DATA_PATH "level_data.plist"

static LevelData* _sharedLevelData = NULL;
LevelData* LevelData::sharedLevelData()
{
    if(_sharedLevelData == NULL){
        _sharedLevelData = new LevelData();
        _sharedLevelData->init();
    }
    return _sharedLevelData;
}
LevelData::LevelData()
{
    _levelDataPath = LEVEL_DATA_PATH;
}
LevelData::~LevelData()
{
    CC_SAFE_RELEASE_NULL(_dictionary);
}
bool LevelData::init()
{
    _dictionary = CCDictionary::createWithContentsOfFile(_levelDataPath.c_str());
    CC_SAFE_RETAIN(_dictionary);
    return true;
}
const char* LevelData::stringFromKey(string key)
{
    return _dictionary->valueForKey(key)->getCString();
}
int LevelData::intFromKey(string key)
{
    return _dictionary->valueForKey(key)->intValue();
}
float LevelData::floatFromKey(string key)
{
    return _dictionary->valueForKey(key)->floatValue();
}
bool LevelData::booleanFromKey(string key)
{
    return _dictionary->valueForKey(key)->boolValue();
}
cocos2d::CCPoint LevelData::pointFromKey(string key)
{
    return CCPointFromString(_dictionary->valueForKey(key)->getCString());
}
cocos2d::CCRect LevelData::rectFromKey(string key)
{
    return CCRectFromString(_dictionary->valueForKey(key)->getCString());
}
cocos2d::CCSize LevelData::sizeFromKey(string key)
{
    return CCSizeFromString(_dictionary->valueForKey(key)->getCString());
}
cocos2d::CCArray* LevelData::arrayFromKey(string key)
{
    return (cocos2d::CCArray*)_dictionary->objectForKey(key);
}
cocos2d::CCDictionary* LevelData::dictFromKey(string key)
{
  return (cocos2d::CCDictionary*)_dictionary->objectForKey(key);
}
void LevelData::purge()
{
    CC_SAFE_RELEASE_NULL(_sharedLevelData);
}
