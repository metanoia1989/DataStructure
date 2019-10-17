#include <stdio.h>
#include <stdlib.h>

typedef struct line {
    struct line *prior; // 指向直接前驱
    int data;
    struct line *next;  // 指向直接后继
} line;

line* initLine(line *head); // 创建双向链表
void display(line *head);   // 输出双向链表
line* insertLine(line* head, int data, int add);    // 双向链表插入元素
line* delLine(line* head, int data);    // 双向链表删除元素
int selectElem(line* head, int elem);   // 双向链表查找元素
line* amendElem(line* p, int add, int newElem); // 双向链表改变指定位置数据

int main(int argc, char const *argv[])
{
    // 创建一个头指针
    line* head = NULL;
    // 调用链表创建函数
    head = initLine(head);
    display(head);
    // 显示双链表的优点
    printf("链表中的第4个节点的直接前驱是：%d\n", head->next->next->next->prior->data);

    // 在表中第3的位置插入元素7
    head = insertLine(head, 7, 3);
    display(head);
    // 表中删除元素2
    head = delLine(head, 2);
    display(head);
    printf("元素3的位置是：%d\n", selectElem(head, 3));
    // 表中第3个节点中的数据改为存储6
    head = amendElem(head, 3, 6);
    display(head);

    return 0;
}

// 创建双向链表
line* initLine(line *head)
{
    // 创建一个首元节点，链表的头指针为 head
    head = (line*)malloc(sizeof(line));
    // 对节点进行初始化
    head->prior = NULL;
    head->next = NULL;
    head->data = 1;
    // 声明一个指向首元节点的指针，方便后期向链表中添加新创建的节点
    line* list = head;
    for (int i=2; i<5; i++) {
        // 创建新的节点并初始化
        line* body = (line*)malloc(sizeof(line));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        // 新节点与链表最后一个节点建立关系
        list->next = body;
        body->prior = list;
        // list永远指向链表中的最后一个节点
        list = list->next;
    }
    // 返回新创建的链表
    return head;
}

void display(line* head)
{
    line* temp = head;
    while (temp) {
        // 如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next == NULL) {
            printf("%d\n", temp->data);
        } else {
            printf("%d <-> ", temp->data);
        }
        temp = temp->next;
    }
}

line* insertLine(line* head, int data, int add)
{
    // 新建数据域为data的节点
    line* temp = (line*)malloc(sizeof(line));
    temp->data = data;
    temp->prior = NULL;
    temp->next = NULL;

    // 插入到链表头
    if (add == 1) {
        temp->next = head;
        head->prior = temp;
        head = temp;
    } else {
        line* body = head;
        // 找到要插入位置的前一个节点
        for (int i = 0; i < add-1; i++) {
            body = body->next;
        }
        // 判断条件为真，说明插入位置为链表尾部
        if (body->next == NULL) {
            body->next = temp;
            temp->prior = body;
        } else {
            body->next->prior = temp;
            temp->next = body->next;
            body->next = temp;
            temp->prior = body;
        }
    }
    return head;
}

line* delLine(line* head, int data)
{
    line* temp = head;
    // 遍历链表
    while (temp) {
        // 判断当前节点中数据域和data是否相等，若相等，摘除该节点
        if (temp->data == data) {
            temp->prior->next = temp->next;
            temp->next->prior = temp->prior;
            free(temp);
            return head;
        }
        temp = temp->next;
    }
    printf("链表中无该数据元素");
    return head;
}

int selectElem(line* head, int elem)
{
    // 新建一个指针t，初始化为头指针 head
    line* t = head;
    int i = 1;
    while (t) {
        if (t->data == elem) {
            return i;
        }
        i++;
        t = t->next;
    }
    return -1;
}

line* amendElem(line* p, int add, int newElem)
{
    line* temp = p;
    // 遍历到被删除的节点
    for (int i = 0; i < add; i++) {
        temp = temp->next;
    }
    temp->data = newElem;
    return p;
}