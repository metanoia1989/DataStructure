#include <iostream>

//*********************************************************************************
// 假设一个无序数组中有若干个正整数，范围是1~100，其中有98个整数出现了偶数次，    
// 只有2个整数出现了奇数次，如何找出奇数次的整数？
// 利用异或运算，相同位得0，不同位得1
// 采用分治法思想，把数组分为两部分，保证每一部分都包含1个出现奇数次的整数
// 这样所有出现偶数次的整数都会相互低效编程0，唯一出现奇数次的整数会被留下  
// 先依次遍历数组做异或运算，结果中至少会有一个二进制位1，这个位的二进制数是不同的
// 按照这个标准进行划分，可以将两个奇数次的数字分到两个数组中
//*********************************************************************************

int* findLostNum(int *arr, int size)
{
    // 用于存储两个出线奇数次的整数    
    int *result = new int[2]{};

    // 第一次整体异或
    int xorResult = 0;
    for (int i = 0; i < size; i++) {
        xorResult ^= arr[i]; 
    }
    // 如果异或结果为0，说明输入数组不符合要求
    if (xorResult == 0) {
        return nullptr;
    }
    // 确定两个整数的不同位，以此来做分组 
    int separator = 1;
    while ((xorResult & separator) == 0) {
        separator <<= 1;
    }
    // 第二次分组异或  z_z 异或真心厉害，位运算牛逼啊
    for (int i = 0; i < size; i++) {
        if ((arr[i] & separator) == 0) {
            result[0] ^= arr[i];
        } else {
            result[1] ^= arr[i];
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4, 1, 2, 2, 5, 1, 4, 3};
    int *result = findLostNum(arr, sizeof(arr) / sizeof(arr[0]));

    std::cout << "两个奇数次出线的整数为：" << result[0] << "," << result[1] << std::endl;
    return 0;
}
