#include <iostream>
#include <vector>
#include <random>
#include <limits>

//****************************************************************
// 红包算法，红包必须满足以下要求
// 1. 所有人强大的金额之和要等于红包金额，不能多也不能少
// 2. 每个人至少抢到1分钱
// 3. 要保证红包拆分的金额尽可能分布均衡，不要出现两极分化太严重的情况
// 
// 二倍均值法
// 每次抢到的金额 = 随机区间 [0.01, m / n x 2 - 0.01] 元
// 每次随机金额的上限定为剩余人均金额的2倍  
//****************************************************************


std::vector<int> divide_red_package(int total_amount, int total_people_num)
{
    std::vector<int> amount_list;    
    int rest_amount = total_amount;
    int rest_people_num = total_people_num;
    
    std::random_device rd;
    std::mt19937 mt(rd());
    
    for (int i = 0; i < total_people_num-1; i++)
    {
        // 随机范围：[1, 剩余人均金额的2倍-1]分
        std::uniform_int_distribution<int> dist(1, rest_amount / rest_people_num * 2 -1);
        int amount = dist(mt);
        rest_amount -= amount;
        rest_people_num--;
        amount_list.push_back(amount);
    }
    amount_list.push_back(rest_amount);
    return amount_list; 
}

int main(int argc, char const *argv[])
{
    std::vector<int> amount_list = divide_red_package(1000, 10);
    std::cout.precision(std::numeric_limits<double>::max_digits10);

    for (auto &i : amount_list)
    {
        std::cout << "抢到的金额为：" << i << " 分" << std::endl; 
    }
    
    return 0;
}
