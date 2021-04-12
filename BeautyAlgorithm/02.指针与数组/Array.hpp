#pragma once
//******************************
// 数组的抽象数据类型
//******************************

#include <iostream>
#include <cstdlib>

const int DefaultSize = 100;

template<typename Type>
class Array
{
public:
    Array(int Size=DefaultSize);
    Array(const Array<Type>& x); // 复制构造函数
    ~Array() { delete []elements; }
    Array<Type> & operator= ( const Array<Type> & rhs); // 数组复制
    Type& operator[](int i); // 取元素值
    int Length() const { return ArraySize; }
    void ReSize(int sz); // 扩充数组

private:
    Type *elements;
    int ArraySize;
};

template<typename Type>
Array<Type>::Array(int Size) 
{
    if (Size <= 0) {
        ArraySize = 0;
        std::cerr << "非法数组大小" << std::endl;
        return;
    }    

    elements = new Type[Size];
    if (elements == nullptr) {
        ArraySize = 0;
        std::cerr << "存储分配错误！" << std::endl;
        exit(1);
    }
    ArraySize = Size;
}

template<typename Type>
Array<Type>::Array(const Array<Type>& x) 
{
    int n = x.ArraySize;
    ArraySize = n;
    elements = new Type[n];
    if (elements == nullptr) {
        ArraySize = 0;
        std::cerr << "存储分配错误！" << std::endl;
        exit(1);
    }
    Type *srcptr = x.elements;
    Type *destptr = elements;
    while (n--) {
        *destptr++ = *srcptr++;
    }
}

template<typename Type>
Array<Type> & Array<Type>::operator= (const Array<Type> & rhs) 
{
    int n = rhs.ArraySize;
    if (ArraySize != n) {
        delete [] elements; // 删除数组原有内存
        elements = new Type[n]; 
        if (elements == nullptr) {
            ArraySize = 0;
            std::cerr << "存储分配错误！" << std::endl;
            exit(1);
        }
        ArraySize = n; // 记录本对象的数组大小
    }
    // 从rhs向本对象复制元素
    Type *destptr = elements;
    Type* srcptr = rhs.elements;
    while (n--) {
        *destptr++ = *srcptr++;
    }
    return *this; // 返回当前对象的引用
}


template<typename Type>
Type& Array<Type>::operator[](int i) 
{
    if (i < 0 || i > ArraySize - 1) {
        std::cerr << "数组下标超界" << std::endl;
        exit(1);
    }
    return elements[i];
}

template<typename Type>
void Array<Type>::ReSize(int sz) 
{
    if (sz >= 0 && sz != ArraySize) {
        Type *newarray = new Type[sz]; // 创建新数组
        if (newarray == nullptr) {
            std::cerr << "存储分配出错" << std::endl;
            return;
        }
        int n = (sz <= ArraySize) ? sz : ArraySize; // 按新的大小确定传送元素

        Type *srcptr = elements; // 源数组指针
        Type *destptr = newarray; // 目标数组指针
        while (n--) {
            *destptr++ = *srcptr++;
        }
        delete [] elements;
        elements = newarray;
        ArraySize = sz;
    }    
}



