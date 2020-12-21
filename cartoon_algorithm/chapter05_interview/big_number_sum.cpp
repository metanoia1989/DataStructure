#include <iostream>
#include <sstream>
#include <string>

//***********************************************************************
// 实现大整数的相加
// 用数组存储大整数，数组的每一个元素对应着大整数的每一个数位
// 创建两个整型数组，数组长度是较大整数的位数加1，把每一个整数倒序存储到数组中
// 数组的个位存储数组下标为0的位置，最高位存于数组的尾部
// 创建结果数组，长度为较大整数的位数加1,
// 遍历两个数组，从左到右按照对应下标把元素两两相加
//***********************************************************************


std::string bigNumberSum(std::string bigNumberA, std::string bigNumberB)
{
    // 1. 把两个大整数用数组逆序存储，数组长度等于较大整数位数+1    
    int maxLength = bigNumberA.length() > bigNumberB.length() ? bigNumberA.length() : bigNumberB.length();
    int *arrA = new int[maxLength+1]();
    for (int i = 0; i < bigNumberA.length(); i++)
    {
        arrA[i] = bigNumberA.at(bigNumberA.length()-1-i) - '0';
    }
    int *arrB = new int[maxLength+1]();
    for (int i = 0; i < bigNumberB.length(); i++)
    {
        arrB[i] = bigNumberB.at(bigNumberB.length()-1-i) - '0';
    }
    
    // 2. 构建result数组，数组长度等于较大整数位数+1
    int *result = new int[maxLength+1]();

    // 3. 遍历数组，按位添加
    for (int i = 0; i < maxLength+1; i++)
    {
        int temp = result[i];
        temp += arrA[i];
        temp += arrB[i];
        // 判断是否进位
        if (temp >= 10) {
            temp -= 10;
            result[i+1] = 1;
        }
        result[i] = temp;
    }
    
    // 4. 把result数组再次逆序并转成string
    bool findFirst = false;
    std::stringstream ss;
    for (int i = maxLength; i >= 0 ; i--)
    {
        if (!findFirst) { // 过滤0
            if (result[i] == 0) 
                continue;
            findFirst = true;
        }
        ss << result[i];
    }
    return ss.str(); 
}

int main(int argc, char const *argv[])
{
    std::string bigNumberA = "426709752318";
    std::string bigNumberB = "95481253129";
    // std::string bigNumberA = "1111";
    // std::string bigNumberB = "2222";

    std::cout << bigNumberA << " + " << bigNumberB << " = " << bigNumberSum(bigNumberA, bigNumberB);

    return 0;
}
