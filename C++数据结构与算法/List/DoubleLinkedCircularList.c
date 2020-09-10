#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    struct line* prior;
    int data;
    struct line* next;
} line;

line* initLine(line* head);
void display(line* head);

int main()
{
    line* head = NULL;
    head = initLine(head);
    display(head);
    return 0;
}

// 创建双向链表
line* initLine(line* head)
{
    head = (line*)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    line* list = head;
    for (int i = 2; i <= 3; i++) {
        line* body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;
        body->prior = list;
        list = list->next;
    }
    // 将链表的首尾节点进行双向连接
    list->next = head;
    head->prior = list;
    return head;
}

void display(line* head)
{
    line* temp = head;
    // 当遍历指针temp指向的下一个节点是head时，已循环至最后一个节点
    while (temp->next != head) {
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        } else {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }
    // 输出循环链表中最后一个节点的值
    printf("%d", temp->data);
}