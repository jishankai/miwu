//
//  Toolkit.h
//  miwu
//
//  Created by wwm on 13-10-20.
//
//

#ifndef __miwu__Toolkit__
#define __miwu__Toolkit__

#include <iostream>
#include "cocos2d.h"

class Toolkit
{
    public:
        static std::string WStrToUTF8(const std::wstring& str);
        static void WStrToUTF8(std::string& dest, const std::wstring& src);
        static void intTostring(int i, std::string& dest);
};

#endif /* defined(__miwu__Toolkit__) */
