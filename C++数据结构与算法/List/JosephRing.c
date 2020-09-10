/**
 * 约瑟夫环问题，是一个经典的循环链表问题，题意是：
 * 已知 n 个人（分别用编号 1，2，3，…，n 表示）围坐在一张圆桌周围，
 * 从编号为 k 的人开始顺时针报数，数到 m 的那个人出列；
 * 他的下一个人又从 1 开始，还是顺时针开始报数，数到 m 的那个人又出列；
 * 依次重复下去，直到圆桌上剩余一个人。
 */

// 假设此时圆周周围有 5 个人，要求从编号为 3 的人开始顺时针数数，数到 2 的那个人出列

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node* next;
} person;

person* initLink(int n);
void findAndKillK(person* head, int k, int m);

int main(int argc, char const *argv[])
{
    printf("删除圆桌上的人数n：");
    int n;
    scanf("%d", &n);
    person* head = initLink(n);
    printf("从第k人开始报数(k>1且k<%d)：", n);
    int k;
    scanf("%d", &k);
    printf("数到m的人出列：");
    int m;
    scanf("%d", &m);
    findAndKillK(head, k, m);

    return 0;
}


// 初始化链表
person* initLink(int n)
{
    person* head = (person*)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    person* cyclic = head;
    for (int i = 2; i <= n; i++) {
        person* body = (person*)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        cyclic->next = body;
        cyclic = cyclic->next;
    }
    cyclic->next = head;    // 首尾相连
    return head; 
}

void findAndKillK(person* head, int k, int m)
{
    person* tail = head;
    // 找到链表第一个节点的上一个节点，为删除操作做准备
    while (tail->next != head) {
        tail = tail->next;
    }
    person* p = head;
    // 找到编号为k的人
    while (p->number != k) {
        tail = p;
        p = p->next;
    }
    // 从编号为k的人开始，只有符号p->next==p时
    // 说明链表中除了p节点，所有编号都出列了
    while(p->next != p) {
        // 从找到p报数1开始，报m的人，并且还要知道数m-1的人的位置tail，方便做删除操作
        for (int i = 1; i < m; i++) {
            tail = p;
            p = p->next;
        }
        tail->next = p->next;   // 从链表上将p节点摘下来
        printf("出列人的编号为：%d\n", p->number);
        free(p);
        p = tail->next; // 继续使用p指针指向出列编号的下一个编号，游戏继续
    }
    printf("出列人的编号为：%d\n", p->number);
    free(p);
}
