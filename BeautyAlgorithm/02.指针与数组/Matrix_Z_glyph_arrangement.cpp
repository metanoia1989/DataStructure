#include <iostream>
#include <iomanip>

//******************************************************************
// 图片的JPEG压缩的Z字形编排
// 对于原始矩阵matrⅸx中的任意元素 matrix[U的遍历走向规律可以分为如下3种情况。
// 如果二维数组中的元素 matrix{]中纵坐标j是偶数,且i=0或者=7,那么遍历路径在矩阵中的走向就是水平向右移动一格。
// 如果二维数组中的元素 matrix[u]中纵坐标是奇数,且j=0或者j=7那么遍历路径在矩阵中的走向就是垂直向下移动一格。
// 除上述规则以外的情况,如果二维数组中的元素matr[][的横纵坐标和t+j是偶数,则遍历路径在矩阵中的走向就是右上角移动一格;
// 否则,若i+j是奇数,则遍历路径在矩阵中的走向就是左下角移动一格。
//******************************************************************

const int SIZE = 8;

int main(int argc, char const *argv[])
{
    int matrix[SIZE][SIZE] = {0};
    int a[SIZE][SIZE] = {0};

    int i, j, x, y, value = 0;

    int *p;
    p = &matrix[0][0];
    // 初始化矩阵
    for(i = 0; i < SIZE * SIZE; i++) {
        *p++ = i; // 先赋值，再移位，这种代码少写为好，难理解
    }

    // 打印原始矩阵
    std::cout <<"原始矩阵如下：" << std::endl;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) 
            std::cout << std::setw(4) << *(*(matrix + i) + j);
        std::cout << std::endl;
    }
    i = 0; j = 0;

    // 进行Z字形编排
    for (x = 0; x < SIZE; x++) {
        for (y = 0; y < SIZE; y++) {
                *(*(a + i) + j) = *(*(matrix + x) + y);
                if ((i == SIZE - 1 || i == 0) && j % 2 == 0) {
                    j++;
                    continue;
                }

                if ((j == SIZE - 1 || j == 0) && i % 2 == 1) {
                    i++;
                    continue;
                }

                if ((i+j)%2 == 0) {
                    i--;
                    j++;
                } else if ((i+j)%2 == 1) {
                    i++;
                    j--;
                }         
        }
    }

    std::cout << std::endl << "经过Z字形编排后的矩阵如下：" << std::endl;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) 
            std::cout << std::setw(4) << *(*(a + i) + j);
        std::cout << std::endl;
    }

    return 0;
}
