/**
 * 假设模拟两个人进行该扑克牌游戏。每个人在游戏过程中都是不断地从自己这一摞扑克牌的最上方去取牌，放到桌子上；
 * 当发现自己的牌同桌子上的牌相等时，将赢得的牌依次放在自己扑克牌的下方。 这是典型的队列的“先进先出”。
 * 而对于桌子而言，就相当于是一个栈。 每次放到桌子上的扑克牌，都相当于进栈；
 * 当有相同的扑克牌时，相同的扑克牌连通之间的所有的扑克牌则依次出栈。 
 * 所以，模拟该扑克牌游戏需要同时使用 2 个队列和 1 个栈。
 */ 
#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data[1000];
    int head;
    int tail;
} queue;

typedef struct stack {
    int data[10];
    int top;
} stack;

void showCard(queue *q, int *book, stack *s);

int main(int argc, char const *argv[])
{
    queue q1, q2;    // 两个队列，分别模拟两个人，假设为小王和小李
    stack s;    // 栈，模拟桌子
    int book[14];   // 方便判断桌子上的牌是否有相同的，增加一个数组用于判断
    int i;
    // 初始化队列
    q1.head = 0; q1.tail = 0;
    q2.head = 0; q2.tail = 0;
    // 初始化栈
    s.top = -1;
    // 初始化用来标记的数组
    for (i=0; i<13; i++) {
        book[i] = 0;
    }
    // 假设初期每个人手中仅有6张牌，每个人拥有的牌都是随机的，但都在1-13之间
    for (i=1; i<=6; i++) {
        q1.data[q1.tail] = rand()%13+1;
        q1.tail++;
    }
    for (i=1; i<=6; i++) {
        q2.data[q2.tail] = rand()%13+1;
        q2.tail++;
    }
    // 仅当一个人没有牌时，游戏结束
    while (q1.head < q1.tail && q2.head < q2.tail) {
        showCard(&q2, book, &s); // 小李出牌
        showCard(&q1, book, &s); // 小王出牌
    }
    // 游戏结束时，输出最后的赢家以及手中剩余的牌数
    if (q2.head == q2.tail) {
        printf("小李赢\n");
        printf("手中还有：%d张牌", q1.tail - q1.head);
    } else {
        printf("小王赢\n");
        printf("手中还有：%d张牌", q2.tail - q2.head);
    }

    return 0;
}

void showCard(queue *q, int *book, stack *s)
{
    // 打出一张牌，即从队列q的队头取元素
    int t = (*q).data[(*q).head]; 
    // 判断取出的这张牌是否会赢牌
    if (book[t] == 0) {// 若不赢牌，只需放到桌子上入栈即可
        (*q).head++;    // 牌已打出，队列的队头需要前进
        (*s).top++;
        (*s).data[(*s).top] = t;    // 再把打出的牌放到桌上，即入栈
        book[t] = 1;    // 标记桌上现在已经有牌面为t的牌
    } else {
        (*q).head++;    // 此时已经打出去一张牌，队头需要 +1
        (*q).data[(*q).tail] = t;   // 将打出的牌放到手中牌的最后(再入列)
        (*q).tail++;
        // 把桌子上赢得的牌依次放到手中牌的最后（依次出栈在入列队的过程）
        while ((*s).data[(*s).top] != t) {
            book[(*s).data[(*s).top]] = 0; // 取消对该牌号的标记
            (*q).data[(*q).tail] = (*s).data[(*s).top]; // 依次放入队尾
            (*q).tail++;
            (*s).top--;
        }
        // 将最后一张相等的牌取出放入队列
        book[(*s).data[(*s).top]] = 0;
        (*q).data[(*q).tail] = (*s).data[(*s).top];
        (*q).tail++;
        (*s).top--;
    }
}