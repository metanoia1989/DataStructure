#include <stdio.h>
#define MAX 5 // 表示顺序表申请的空间大小

int enQueue(int *a, int front, int rear, int data);
int deQueue(int *a, int front, int rear);

int main()
{
    int a[MAX];
    int front, rear;
    // 设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    front = rear = 0;
    // 入列
    rear = enQueue(a, front, rear, 1);
    rear = enQueue(a, front, rear, 2);
    rear = enQueue(a, front, rear, 3);
    rear = enQueue(a, front, rear, 4);
    // 出列
    front = deQueue(a, front, rear);
    // 再入列
    rear = enQueue(a, front, rear, 5);
    // 再出列
    front = deQueue(a, front, rear);
    // 再入列
    rear = enQueue(a, front, rear, 6);
    // 再出列
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    front = deQueue(a, front, rear);
    return 0;
}

int enQueue(int *a, int front, int rear, int data)
{
    // 添加判断语句，如果 rear 超过 max，则直接将其从 a[0] 重新开始存储，如果 rear+1 和 front 重合，则表示数组已满
    if ((rear+1) % MAX == front) {
        printf("空间已满");
        return rear;
    }
    a[rear % MAX] = data;
    rear++;
    return rear;
}

int deQueue(int *a, int front, int rear)
{
    // 如果 front == rear，表示队列为空
    if (front == rear % MAX) {
        printf("队列为空");
        return front;
    }
    printf("%d", a[front]);
    // front 不再直接+1，而是+1后同MAX进行比较，如果=MAX，则直接跳转到 a[0]
    front = (front+1) % MAX;
    return front;
}