#include <iostream>

/**
 * N 皇后问题
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens' placement, 
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 怎么用枚举、回溯法来解决呢？这个问题看来真的有点难度了，之前抄人家的代码，没有理解其中的含义，白白浪费了时间     
 * 单个解法不难，但是找出所有的解法我有点不太懂怎么弄   
 * 其中一个关键点是检测皇后是否安全，不在同一行、不在同一列、不在统一斜线上 
 * queue 的 column 上没有其他棋子
 * queue 的 row 上没有其他棋子
 * 
 */ 
void solveNQueues(int n)
{
    int board[n][n] = {0};     
}

