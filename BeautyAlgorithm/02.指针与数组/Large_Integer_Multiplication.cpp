#include <iostream>
#include <memory.h>

//*************************************************************************************************
// 大整数乘法
// 计算机的精度是有限的，因此单纯使用程序设计语言提供的原子型数据类型来完成两个大整数的乘法显然是不切实际的。
// 可以考虑用两个数组来分别存储一些小于10的整数，这些数字按顺序排列在一起，分别表示一个大整数每一位上的数字，
// 于是大整数的存储问题就解决了然后按照基本乘法规则对这两个大整数进行运算即可。
//*************************************************************************************************

const int SIZE = 14;

/**
 * 返回两个大整数的积
 * 返回位数为 size1 + size2
 *  
 * @param  {int*} num1 : 
 * @param  {int} size1 : 
 * @param  {int*} num2 : 
 * @param  {int} size2 : 
 * @return {int*}      : 
 */
int* multiple(int* num1, int size1, int* num2, int size2)
{
    int size = size1 + size2;
    int* ret = new int[size];

    for (int i = 0; i < size; i++) 
        ret[i] = 0;
    
    for (int i = 0; i < size2; i++) {
        int k = i;
        for (int j =0; j < size1; j++) {
            ret[k++] += num2[i] * num1[j];
        }
    }

    // 进位处理
    for (int i = 0; i < size; i++) {
        if (ret[i] >= 10) {
            ret[i+1] += ret[i] / 10;
            ret[i] %= 10;
        }
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    int num1[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 1, 1, 1, 1 }; // 11111987654321
    int num2[SIZE] = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5 }; // 55444333222111

    int* ret = multiple(num1, SIZE, num2, SIZE);

    // 倒叙输出
    for (int i = SIZE*2 - 1; i >= 0; i--) 
        std::cout << ret[i];
    delete [] ret; // 释放内存

    return 0;
}
