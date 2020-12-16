#include <iostream>

//*****************************************************************************
// 判断是否是2的整数次幂
// 方法1 创建一个临时变量temp=1，循环倍增，与目标整数比较，如果相等则是2的整数次幂
// 如果大于目标数则结束循环拿到结果 
// 
// 方法2 乘2改成向左移位，利用位运算来提高性能
// 
// 方法3 将十进制数转换为二进制数，当是2的整数次幂时，其最高位为1，其他位都是0
// 一旦减1，则所有的二进制位都变成了1，则 n & (n - 1) = 0
//*****************************************************************************

bool isPowerOf2_one(int num)
{
    int temp = 1;    
    while (temp <= num) {
        if (temp == num) {
            return true;
        }
        temp *= 2;
    }
    return false;
}

bool isPowerOf2_two(int num)
{
    int temp = 1;    
    while (temp <= num) {
        if (temp == num) {
            return true;
        }
        temp = temp << 1;
    }
    return false;
}

bool isPowerOf2_three(int num)
{
    return (num & (num - 1)) == 0; 
}

int main(int argc, char const *argv[])
{
    int arr[] = { 8, 16, 32, 64, 100 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "===================isPowerOf2_one===================" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << "是否为2的整数次幂：" << isPowerOf2_one(arr[i]) << std::endl;
    }

    std::cout << "===================isPowerOf2_two===================" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << "是否为2的整数次幂：" << isPowerOf2_two(arr[i]) << std::endl;
    }

    std::cout << "===================isPowerOf2_three===================" << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i] << "是否为2的整数次幂：" << isPowerOf2_three(arr[i]) << std::endl;
    }
    

    return 0;
}
