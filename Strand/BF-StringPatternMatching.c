#include <stdio.h>
#include <string.h>

int mate(char *B, char *A);

int main()
{
    int number = mate("ababcabcacbab", "abcac");
    printf("%d", number);
    return 0;
}




// 串普通模式匹配算法的实现，B为伪主串，A是伪子串
int mate(char *B, char *A)
{
    int i = 0, j = 0;
    while (i < strlen(B) && j < strlen(A)) {
        if (B[i] == A[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    // 跳出循环的两种方式：i == strlen(B) 说明已经遍历完主串，匹配失败
    // j == strlen(A) 说明子串遍历完成，在主串成功匹配
    if (j == strlen(A)) {
        return i = strlen(A) + 1;
    }
    // 运行到此为止 为 i == strlen(B) 的情况
    return 0;
}