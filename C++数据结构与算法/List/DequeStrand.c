// 串的堆分配存储结构

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *a1 = NULL;
    char *a2 = NULL;
    a1 = (char*)malloc(10 * sizeof(char));
    strcpy(a1, "data.bian");    // 将字符串 "data.bian" 复制给a1
    a2 = (char*)malloc(10 * sizeof(char));
    strcpy(a2, "cheng.net");
    int lengthA1 = strlen(a1);  // a1串的长度
    int lengthA2 = strlen(a2);  // a2串的长度

    // 尝试将合并的串存储在a1中，如果a1空间不够，则用 realloc 动态申请
    if (lengthA1 < lengthA1 + lengthA2) {
        a1 = (char*)realloc(a1, (lengthA1 + lengthA2 + 1) * sizeof(char));
    }
    // 合并两个串到 a1 中
    for (int i = lengthA1; i < lengthA1 + lengthA2; i++) {
        a1[i] = a2[i - lengthA1];
    }
    // 串的末尾要添加 \0，避免出错
    a1[lengthA1 + lengthA2] = '\0';
    printf("%s", a1);
    // 用完动态数组要立即释放
    free(a1);
    free(a2);

    return 0;
}
