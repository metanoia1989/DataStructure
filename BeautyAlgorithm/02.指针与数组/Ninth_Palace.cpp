#include <iostream>
#include <iomanip>
#include <memory.h>

int main(int argc, char const *argv[])
{
    std::cout << "请输入幻方的大小n（n是一个大于1的奇数）：";
    int n = 1;
    std::cin >> n;
    std::cout << std::endl;

    int **a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        for (int j = 0; j < n; j++) 
            a[i][j] = 0;
    }

    int row = 0;
    int col = n / 2;

    for (int i = 1; i <= n*n; i++) {
        a[row][col] = i;
        row--;
        col++;

        if (row < 0 && col >= n) {
            col--;
            row += 2;
        } else if (row < 0) {
            row = n - 1;
        } else if (col >= n) {
            col = 0;
        } else if (a[row][col] != 0) {
            col--;
            row += 2;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << std::setw(6) << a[i][j];
        std::cout << std::endl;
    }

    for (int i = n; i > 0; ) 
        delete[] a[--i];
    delete[] a;
    
    return 0;
}
