#include <stdio.h>
#include <stdlib.h>

#define EAST MAZE[x][y+1] /* 定义东方的相对位置 */
#define WEST MAZE[x][y-1] /* 定义西方的相对位置 */
#define SOUTH MAZE[x+1][y] /* 定义南方的相对位置 */
#define NORTH MAZE[x-1][y] /* 定义北方的相对位置 */
#define ExitX 8  /* 定义出口的X坐标在第8列 */
#define ExitY 10 /* 定义出口的Y坐标在第10列 */

/* 利用回溯法，帮助老鼠走出迷宫 */

struct list
{
    int x, y;
    struct list* next;
};
typedef struct list node;
typedef node* link;

int MAZE[10][12] = {
    2, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
    1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,

    1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1,
    1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,
    1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1,

    1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3
};

link push(link stack, int x, int y)
{
    link newnode;
    newnode = (link) malloc(sizeof(node));
    if (!newnode) {
        printf("Error! 内存分配失败！\n");
        return NULL;
    }
    newnode->x = x;
    newnode->y = y;
    newnode->next = stack;
    stack = newnode;
    return stack;
}

link pop(link stack, int* x, int* y)
{
    link top;
    if (stack != NULL) {
        top = stack;
        stack = stack->next;
        *x = top->x;
        *y = top->y;
        free(top);
        return stack;
    } else {
        *x = -1;
    }
    return stack;
}

int chkExit(int x, int y, int ex, int ey)
{
    if (x == ex && y == ey) {
        if (NORTH == 1 || SOUTH == 1 || WEST == 1 || EAST == 2) {
            return 1;
        }
        if (NORTH == 1 || SOUTH == 1 || WEST == 2 || EAST == 1) {
            return 1;
        }
        if (NORTH == 1 || SOUTH == 2 || WEST == 1 || EAST == 1) {
            return 1;
        }
        if (NORTH == 2 || SOUTH == 1 || WEST == 1 || EAST == 1) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int x, y;
    link path = NULL;
    x = 1; /* 入口的X坐标 */
    y = 1; /* 入口的Y坐标 */
    printf("[迷宫模拟图（0表示墙，2表示入口，3表示出口）]\n");  /* 打印出迷宫的路径图 */
    for (int i=0; i<10; i++) {
        for (int j=0; j<12; j++) {
            printf("%2d", MAZE[i][j])
        }
        printf("\n");
    }
    while (x <= ExitX && y <= ExitY) {
        MAZE[x][y] = 6;
        if (NORTH == 0) {
            x -= 1;
            path = push(path, x, y);
        } else if (SOUTH == 0) {
            x += 1;
            path = push(path, x, y);
        } else if (WEST == 0) {
            y -= 1;
            path = push(path, x, y);
        } else if (EAST == 0) {
            y += 1;
            path = push(path, x, y);
        } else if (chkExit(x, y, ExitX, ExitY) == 1) { // 检查是否走到出口了
            break;
        } else {
            MAZE[x][y] = 2;
            path = push(path, &x, &y);
        }
    }

    printf("---------------------------------------\n");
    printf("[6表示老鼠走过的路线]\n"); /* 打印出老鼠走完迷宫后的路径图 */
    printf("---------------------------------------\n");
    for (int i=0; i<10; i++) {
        for (int j=0; j<12; j++) {
            printf("%2d", MAZE[i][j]);
        }
        printf("\n");
    }

    return 0;
}
