// 单链表

#include <stdio.h>
#include <stdlib.h>

// 链表的节点结构
typedef struct Link 
{
    int elem;
    struct Link *next;
} link;

link* initLink();   // 初始化无头节点链表
link* initLink2();   // 初始化有头节点链表
void display(link *p);  // 输出链表元素
link* insertElem(link *p, int elem, int add);
link* delElem(link *p, int add);    
int selectElem(link *p, int elem);
link* amendElem(link *p, int add, int newElem); 

int main(int argc, char const *argv[])
{
    // 初始化链表(1, 2, 3, 4)
    printf("初始化链表为：\n");
    link *p = initLink2();
    display(p);

    printf("在第4的位置插入元素5：\n");
    p = insertElem(p, 5, 4);
    display(p);

    printf("删除元素3：\n");
    p = delElem(p, 3);
    display(p);

    printf("查找元素2的位置为：\n");
    int address = selectElem(p, 2);
    if (address == -1) {
        printf("没有该元素");
    } else {
        printf("元素2的位置为：%d\n", address);
    }

    printf("更改第3的位置上的数据为7：\n");
    p = amendElem(p, 3, 7);
    display(p);

    return 0;
}

// 创建无头节点的链表
link* initLink()
{
    link *p = NULL; // 创建头指针
    link *temp = (link*) malloc(sizeof(link)); // 创建首元节点
    // 首元节点初始化
    temp->elem = 1;
    temp->next = NULL;
    p = temp;   // 头指针指向首元节点
    for (int i=2; i<5; i++) {
        // 创建一个新节点并初始化
        link *a = (link*) malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;

        temp->next = a; // 将temp节点与新建立的节点建立逻辑关系
        temp = temp->next; // 指针temp每次都指向新链表的最后一个节点
    }
    // 返回节点的节点，返回头指针p，通过头指针可找到整个链表
    return p;
}

// 创建有头节点的链表
link* initLink2()
{
    link *p = (link*)malloc(sizeof(link)); // 创建一个头节点
    link *temp = p; // 声明一个指针指向头节点
    // 生成链表
    for (int i=1; i<5; i++) {
        link *a = (link*) malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;

        temp->next = a;
        temp = temp->next;
    }
    return p;
}

void display(link *p)
{
    link *temp = p; // 创建临时指针，迭代链表
    // 只要temp指针指向的节点的next不是NULL就执行输出语句
    while (temp->next) {
        temp = temp->next;
        printf("%d", temp->elem);
    }
    printf("\n");
}

// 链表插入元素 elem 为新数据元素，add 表示新元素要插入的位置
link* insertElem(link *p, int elem, int add)
{
    link *temp = p; // 创建临时节点 temp
    // 找到要插入位置的上一个节点
    for (int i=1; i<add; i++) {  // 链表没有索引，查找元素只能一次迭代
        temp = temp->next;
        if (temp == NULL) {
            printf("插入位置无效\n");
            return p;
        }
    }
    // 创建插入节点c
    link *c = (link*) malloc(sizeof(link));
    c->elem = elem;
    // 向链表中插入节点
    c->next = temp->next;
    temp->next = c;
    return p;
}

// 链表删除元素，p 为原链表，add为要删除元素的值
link* delElem(link *p, int add)
{
    link *temp = p;
    // 遍历到被删除节点的上一个节点
    for (int i=1; i<add; i++) {
        temp = temp->next;
        if (temp->next == NULL) {
            printf("没有该节点\n");
            return p;
        }
    }
    link *del = temp->next;  // 用于释放被删除节点的内存
    temp->next = temp->next->next;  // 更改前一个节点的指针域即可删除节点
    free(del);  // 手动释放被删除节点的内存，防止内存泄漏
    return p;
}

// 链表查找元素
int selectElem(link *p, int elem)
{
    // 新建一个指针t，初始化为头指针p
    link *t = p;
    int i = 1;
    // 由于头节点的存在，第一个元素为 t->next
    while(t->next) {
        t = t->next;
        if (t->elem == elem) {
            return i;
        }
        i++;
    }
    return -1;
}

// 链表更新元素
link* amendElem(link *p, int add, int newElem)
{
    link *temp = p;
    temp = temp->next;  // temp 指向首元节点;
    // 遍历到待更新节点
    for (int i=1; i<add; i++) {
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}
