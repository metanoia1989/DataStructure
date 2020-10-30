#include <iostream>
#include <functional>
#include <string>

/**
 * N 皇后问题
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * Each solution contains a distinct board configuration of the n-queens' placement, 
 * where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 怎么用枚举、回溯法来解决呢？这个问题看来真的有点难度了，之前抄人家的代码，没有理解其中的含义，白白浪费了时间     
 * 单个解法不难，但是找出所有的解法我有点不太懂怎么弄   
 * 其中一个关键点是检测皇后是否安全，不在同一行、不在同一列、不在统一斜线上 
 * 一般来说一列只会放一个，所以列不用检测了，检测行是否冲突就可以了
 *
 * 找一个还好点，怎么找到所有的解呢？       
 */ 
template <int N>
class NQueensProblem
{
public:
    /**
     * 输出皇后的位置
     */
    void printQueens() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                std::cout << grid[i][j] << " "; 
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    
    /**
     * 皇后在此位置是否安全
     *
     * @param  {int} col : 
     * @param  {int} row : 
     * @return {bool}    : 
     */
    bool isSafe(int col, int row){
        // 检测是否在同一行
        for (int i = 0; i < row; i++) {
            if (grid[i][col]) 
                return false; 
        }
        // 检测是否在左上角的斜线
        for (int i = row, j = col; i >= 0 && j >= 0 ; i--, j--) {
            if (grid[i][j])
                return false;
        }
        // 检测是否在右上角的斜线 
        for (int i = row, j = col; i >= 0 && j < N ; i--, j++) {
            if (grid[i][j])
                return false;
        }
        return true; 
    }

    /**
     * N皇后的求解方法，发现每一个皇后的位置
     * @param  {int} row : 皇后的序号
     * @return {bool}    : 
     */
    bool solve(int row)  
    {
        if (row == N) {
            printQueens(); // 打印皇后可能的位置
            return true;
        }
        bool res = false; // N-Queens 是否有解
        for (int i = 0; i < N; i++) { // -> 调用N次 
            if (isSafe(i, row)) {
                grid[row][i] = 1;
                res = solve(row+1) || res;
                grid[row][i] = 0;
            }
        }
        return res;
    }

private:    
    int grid[N][N] = {0};
};

int main(int argc, char const *argv[])
{
    const int n = 5;
    auto problem = NQueensProblem<n>();
    std::cout << "开始解决" + std::to_string(n) + "皇后问题" << std::endl;

    // 调用求解方法
    bool res = problem.solve(0);
    if (res) {
        std::cout << std::endl;
    } else {
        std::cout << std::to_string(n) + " Queens is no possible solution" << std::endl;
    }

    return 0;
}


