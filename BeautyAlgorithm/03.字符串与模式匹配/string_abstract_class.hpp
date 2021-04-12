#pragma once


//*********************************************
// 字符串抽象数据类型
//*********************************************
#include <string.h>

const int maxLen = 128;

class String
{
public:
    String(const String& ob);
    String(const char* init);
    String();

    ~String() { delete[] c; }    

    int Length() const { return curLen; } // 求当前字符串的实际长度
    int Find(String& pat) const; // 在当前字符串中查找目标字符串 

    // 取当前字符串中从pos开始的len个字符组成的子字符串
    String &operator()(int pos, int len);
    // 判断当前字符串与对象串ob是否相等
    int operator==(const String &ob) const {
    }

private:
    int curLen; // 字符串的长度
    char *c; // 字符串的存储数组
};
