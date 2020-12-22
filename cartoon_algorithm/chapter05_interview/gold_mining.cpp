#include <iostream>
#include <vector>
#include <algorithm>

//***********************************************************************************
// 很久很久以前，有一位国王拥有5座金矿，每座金矿的黄金储量不同，需要参与
// 挖掘的工人人数也不同。例如有的金矿储量是500kg黄金，需要5个工人来挖掘；有
// 的金矿储量是200kg黄金，需要3个工人来挖掘……
//
// 如果参与挖矿的工人的总数是10。每座金矿要么全挖，要么不挖，不能派出一
// 半人挖取一半的金矿。要求用程序求出，要想得到尽可能多的黄金，应该选择挖取
// 哪几座金矿？
// 
// 我们把金矿数量设为n，工人数量设为 w，金矿的含金量设为数组g[]，金矿所需开采人数设为数组p[]，
// 设F（n，w）为n个金矿、w个工人时的最优收益函数，那么状态转移方程式如下。
// 问题边界，金矿数为0或工人数为0的情况。
// F(n,w) = 0 (n=0或w=0) 
// 当所剩工人不够挖掘当前金矿时，只有一种最优子结构。
// F(n,w) = F(n-1,w) (n≥1, w<p[n-1])  
// 在常规情况下，具有两种最优子结构（挖当前金矿或不挖当前金矿）。
// F(n,w) = max(F(n-1,w), F(n-1,w-p[n-1])+g[n-1]) (n≥1, w≥p[n-1]) 
//***********************************************************************************

// 利用递归使用状态转移方程来解决问题
/**
 * 获取金矿最优收益，递归实现
 * @param  {int} w              : 工人数量
 * @param  {int} n              : 可选金矿数量
 * @param  {std::vector<int>} p : 金矿开采所需工人数量
 * @param  {std::vector<int>} g : 金矿储量
 * @return {int}                : 
 */
int getBestGoldMiningRecursion(int w, int n, std::vector<int> p, std::vector<int> g)
{
    if (w == 0 || n == 0) {
        return 0;
    }    
    
    if (w < p [n-1]) {
        return getBestGoldMiningRecursion(w, n - 1, p, g);
    }
    return std::max(getBestGoldMiningRecursion(w, n-1, p, g), getBestGoldMiningRecursion(w-p[n-1], n-1, p, g)+g[n-1]);
}

/**
 * 获取金矿最优收益，缓存表法
 *
 * @param  {int} w              : 工人数量
 * @param  {std::vector<int>} p : 金矿开采所需工人数量
 * @param  {std::vector<int>} g : 金矿储量
 * @return {int}                : 
 */
int getBestGoldMiningCacheTable(int w, std::vector<int> p, std::vector<int> g)
{
    // 创建表格
    std::vector<std::vector<int>> resultTable(g.size()+1, std::vector<int>(w+1));
    // 填充表格 
    for (int i = 1; i <= g.size(); i++) {
        for (int j = 1; j <= w; j++) {
            if (j < p[i-1]) {
                resultTable[i][j] = resultTable[i-1][j];
            } else {
                resultTable[i][j] = std::max(resultTable[i-1][j], resultTable[i-1][j-p[i-1]]+g[i-1]);
            }
        }
    }
    // 返回最后一个格子的值 
    return resultTable[g.size()][w];
}

int getBestGoldMiningReduction(int w, std::vector<int> p, std::vector<int> g)
{
    // 创建当前结果 
    std::vector<int> results(w+1);
    
    // 填充一位数组
    for (int i = 1; i <= g.size(); i++) {
        for (int j = w; j >= 1; j--) {
            if (j >= p[i-1]) {
                results[j] = std::max(results[j], results[j-p[i-1]] + g[i-1]);
            }
        }
    }
    // 返回最后一个格子的值 
    return results[w];
}

int main(int argc, char const *argv[])
{
    int w = 10;
    std::vector<int> p = { 5, 5, 3, 4, 3 }; // 金矿开采所需工人数量
    std::vector<int> g = { 400, 500, 200, 300, 350 }; // 金矿的含金量
    std::cout << "最优收益 递归实现：" << getBestGoldMiningRecursion(w, g.size(), p, g) << std::endl;
    std::cout << "最优收益 缓存表法：" << getBestGoldMiningCacheTable(w, p, g) << std::endl;
    std::cout << "最优收益 状态推导：" << getBestGoldMiningReduction(w, p, g) << std::endl;

    return 0;
}
