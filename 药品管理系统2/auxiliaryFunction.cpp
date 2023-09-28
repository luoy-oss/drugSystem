#include <codecvt>
#include <comutil.h>
#include <string>
#pragma comment(lib, "comsuppw.lib")
#include "auxiliaryFunction.h"

#define _MIN(x,y) (((x)<(y))?(x):(y))


std::string wstringTostring(const std::wstring& ws) {
    _bstr_t t = ws.c_str();
    char* pchar = (char*)t;
    std::string result = pchar;
    return result;
}

std::wstring stringTowstring(const std::string& s) {
    _bstr_t t = s.c_str();
    wchar_t* pwchar = (wchar_t*)t;
    std::wstring result = pwchar;
    return result;
}

