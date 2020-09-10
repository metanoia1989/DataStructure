// 顺序结构模拟俄罗斯轮盘赌博

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


typedef struct line {
    int No;
    struct line *next;
} line;

// 初始化链表
void initLine(line **head, int n);
// 输出链表
void display(line *head);

int main()
{
    line *head = NULL;
    srand((int)time(0));
    int n, shootNum, round = 1;
    printf("输入赌徒人数：");
    scanf("%d", &n);
    initLine(&head, n);
    line *lineNext = head;  // 用于记录每轮开始的位置
    // 仅当链表中只含有一个节点时，即头节点时，退出循环
    while (head->next != head) {
        printf("第%d轮开始，从编号为%d的人开始，", round, lineNext->No);
        shootNum = rand()%n + 1;
        printf("枪在第%d次扣动扳机时会响\n", shootNum);
        line *temp = lineNext;
        // 遍历循环链表，找到将要删除节点的上一个节点
        for (int i = 1; i < shootNum - 1; i++) {
            temp = temp->next;
        }
        // 将要删除节点从链表中删除，并释放其占用控件
        printf("编号为%d的赌徒退出赌博，剩余赌徒编号依次为：\n", temp->next->No);
        line *del = temp->next;
        temp->next = temp->next->next;
        if (del == head) {
            head = head->next;
        }
        free(del);
        display(head);
        // 赋值新一轮开始的位置
        lineNext = temp->next;
        round++;    // 记录循环次数
    }
    printf("最终胜利的赌徒编号是：%d\n", head->No);
    return EXIT_SUCCESS;
}

// 按照赌徒人数，初始化循环链表
void initLine(line **head, int n)
{
    *head = (line*)malloc(sizeof(line));
    (*head)->next = NULL;
    (*head)->No = 1;
    line *list = *head;
    for (int i = 1; i < n; i++) {
        line *body = (line*)malloc(sizeof(line));
        body->next = NULL;
        body->No = i + 1;
        list->next = body;
        list = list->next;
    }
    list->next = *head; // 将链表成环
}

// 输出链表中所有节点信息
void display(line *head)
{
    line *temp = head;
    while (temp->next != head) {
        printf("%d", temp->No);
        temp = temp->next;
    }
    printf("%d\n", temp->No);
}