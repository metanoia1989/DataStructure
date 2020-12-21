#include <iostream>
#include <string>

//********************************************************************************************
// 删除去一个整数k个数字后其值最小
// 先求得删除一个数字后整数值最小，从高位开始依次比较，如果相邻的高位值比地位大，则删除此高位即可。
// 然后这样依次求得局部最优解，最终得到全局最优解的，运用了贪心算法的思想   
//********************************************************************************************


// 下面这个方法的时间复杂度为O(kn)
// string::substr() 本身性能不高，其底层实现涉及新字符串的创建，以及逐个字符的复制，方法本身的时间复杂度为O(n)
/**
 * 删除整数的k个数字，获得删除后的最小值
 *
 * @param  {std::string} num : 原整数
 * @param  {int} k           : 删除数量
 * @return {std::string}     : 
 */
std::string removeKDigits(std::string num, int k)
{
    for (int i = 0; i < k; i++) {
        bool hasCut = false;
        // 从左向右遍历，找到比自己右侧数字大的数字并删除   
        for (int j = 0; j < num.length() - 1; j++) {
            if (num.at(j) < num.at(j+1)) {
                continue;
            }
            num = num.substr(0, j) + num.substr(j+1, num.length());
            hasCut = true;
            break;
        }
        // 如果没有找到要删除的数字，则删除最后一个数字
        if (!hasCut) {
            num = num.substr(0, num.length() - 1);    
        } 
    }
    // 清除整数左侧的数字0
    size_t first = num.find_first_not_of('0');
    if (first != std::string::npos) {
        num = num.substr(first, num.length() - first + 1);
    }
    // 如果整数的所有数字都被删除了，直接返回0     
    if (num.length() == 0) {
        return "0";
    }
    return num;
}

// 以遍历数字作为外循环，以k作为内循环
/**
 * 删除整数的k个数字，获得删除后的最小值 - 加速版
 *
 * @param  {std::string} num : 原整数
 * @param  {int} k           : 删除数量
 * @return {std::string}     : 
 */
std::string removeKDigitsSpeed(std::string num, int k)
{
    // 新整数的最终长度 = 原整数长度 - k 
    int newLength = num.length() - k;
    // 创建一个栈，用于接收所有的数字
    char *stack = new char[num.length()];
    int top = 0;
    for (int i = 0; i < num.length(); i++) {
        // 遍历当前数字
        char c = num.at(i);
        // 当栈顶数字大于遍历到的当前数字，栈顶数字出栈，等同于删除数字
        while (top > 0 && stack[top - 1] > c && k > 0) {
            top--; 
            k--;
        }
        // 如果遇到数字0，且栈为空，0不入栈
        if (c == '0' && top == 0) {
            newLength--;
            if (newLength <= 0) {
                return "0";
            }
            continue;
        }
        // 遍历到的当前数字入栈
        stack[top++] = c;
    }
    // 用栈构建新的整数字符串 
    return newLength <= 0 ? "0" : std::string(stack, 0, newLength);
}

int main(int argc, char const *argv[])
{
    std::cout << "1593212移除3个数字后的最小值是：" << removeKDigits("1593212", 3) << std::endl;
    std::cout << "30200移除1个数字后的最小值是：" << removeKDigits("30200", 1) << std::endl;
    std::cout << "10移除2个数字后的最小值是：" << removeKDigits("10", 2) << std::endl;
    std::cout << "541270936移除3个数字后的最小值是：" << removeKDigits("541270936", 3) << std::endl;
    std::cout << "1593212移除4个数字后的最小值是：" << removeKDigits("1593212", 4) << std::endl;
    std::cout << "1000020000000010移除2个数字后的最小值是：" << removeKDigits("1000020000000010", 2) << std::endl;

    std::cout << "========================== 性能优化版 =====================" << std::endl;
    std::cout << "1593212移除3个数字后的最小值是：" << removeKDigitsSpeed("1593212", 3) << std::endl;
    std::cout << "30200移除1个数字后的最小值是：" << removeKDigitsSpeed("30200", 1) << std::endl;
    std::cout << "10移除2个数字后的最小值是：" << removeKDigitsSpeed("10", 2) << std::endl;
    std::cout << "541270936移除3个数字后的最小值是：" << removeKDigitsSpeed("541270936", 3) << std::endl;
    std::cout << "1593212移除4个数字后的最小值是：" << removeKDigitsSpeed("1593212", 4) << std::endl;
    std::cout << "1000020000000010移除2个数字后的最小值是：" << removeKDigitsSpeed("1000020000000010", 2) << std::endl; // 有点BUG哈
    return 0;
}
