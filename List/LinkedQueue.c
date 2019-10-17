#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;

QNode* initQueue();
QNode* enQueue(QNode *rear, int data);
QNode* deQueue(QNode *top, QNode *rear);

int main(int argc, char const *argv[])
{
    QNode *queue, *top, *rear;
    queue = top = rear = initQueue();  // 创建头节点
    // 向链队列中添加节点，使用尾插法添加的同时，队尾指针需要指向链表的最后一个元素
    rear = enQueue(rear, 1);
    rear = enQueue(rear, 2);
    rear = enQueue(rear, 3);
    rear = enQueue(rear, 4);
    // 入列完成，所有数据元素开始出队列
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);
    rear = deQueue(top, rear);

    return 0;
}

QNode* initQueue()
{
    QNode *queue = (QNode*)malloc(sizeof(QNode));
    queue->next = NULL;
    return queue;
}

QNode* enQueue(QNode *rear, int data)
{
    QNode *enElem = (QNode*)malloc(sizeof(QNode));
    enElem->data = data;
    enElem->next = NULL;
    // 使用尾插法向链队列中添加数据元素
    rear->next = enElem;
    rear = enElem;
    return rear;
}

QNode* deQueue(QNode *top, QNode *rear)
{
    if (top->next == NULL) {
        printf("\n队列为空");
        return rear;
    }
    QNode *p = top->next;
    printf("%d", p->data);
    top->next = p->next;
    if (rear == p) {
        rear = top;
    }
    free(p);
    return rear;
}