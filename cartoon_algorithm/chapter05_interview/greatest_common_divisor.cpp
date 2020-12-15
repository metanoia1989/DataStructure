#include <iostream>

//************************************************************************
// 最大公约数求解 greatest common divisor GCD
// 最大公约数的用途：密码学、分数约分通分、哈希表防止哈希冲突的取模操作
//
// 欧几里得算法 Euclidean algorithm 又名辗转相除法
// 两个正整数a和b并且 a>b，它们的最大公约数等于a除以b的余数c和b之间的最大公约数
// 公式 gcd(A, B) = gcd(B, A mod B)   其中:A > B
// 
// 更相减损法 出自九章算术
// 两个正整数a和b并且 a>b，它们的最大公约数等于a-b的差值c和较小数b的最大公约数
// 公式 
// 如果A > B，则 gcd(A,B) = gcd(B,A-B)
// 如果A < B，则 gcd(A,B) = gcd(A,B-A)
//************************************************************************
// 这篇博客写的真好https://blog.csdn.net/Holmofy/article/details/76401074

/**
 * 辗转相除法
 */
int euclidea_algorithm_gcd(int a, int b)
{
    int big = a > b ? a : b;    
    int small = a < b ? a : b;
    if (big % small == 0) {
        return small;
    }
    return euclidea_algorithm_gcd(big%small, small);
}

/**
 * 更相减损术
 */
int decreases_technique_gcd(int a, int b)
{
    if (a == b) {
        return a;
    } 
    int big = a > b ? a : b;    
    int small = a < b ? a : b;
    return decreases_technique_gcd(big-small, small);
}

int main(int argc, char const *argv[])
{
    std::cout << "==========欧几里得算法==========" << std::endl;
    std::cout << "25和5的最大公约数为：" << euclidea_algorithm_gcd(25, 5) << std::endl; 
    std::cout << "100和80的最大公约数为：" << euclidea_algorithm_gcd(100, 80) << std::endl; 
    std::cout << "27和14的最大公约数为：" << euclidea_algorithm_gcd(27, 14) << std::endl; 

    std::cout << "==========更相减损术算法==========" << std::endl;
    std::cout << "25和5的最大公约数为：" << decreases_technique_gcd(25, 5) << std::endl; 
    std::cout << "100和80的最大公约数为：" << decreases_technique_gcd(100, 80) << std::endl; 
    std::cout << "27和14的最大公约数为：" << decreases_technique_gcd(27, 14) << std::endl; 

    return 0;
}
