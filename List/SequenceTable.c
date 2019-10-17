// 顺序表

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Table {
    int* head;  //声明了一个名为head的长度不确定的数组，也叫“动态数组”
    int length;  //记录当前顺序表的长度
    int size;  //记录顺序表分配的存储容量
} table;

table initTable();  // 初始化顺序表
void displayTable(table t); // 输出顺序表元素
table addTable(table t, int elem, int add);   // 顺序表插入元素
table delTable(table t, int add); // 删除元素
int selectTable(table t, int elem); // 查找元素
table amendTable(table t, int elem, int newElem);   // 修改元素

int main(int argc, char const *argv[])
{
    table t1 = initTable();

    // 向顺序表中添加元素
    for (int i=1; i<=SIZE; i++) {
        t1.head[i-1] = i; 
        t1.length++;
    }

    printf("原顺序表：\n");
    displayTable(t1);

    printf("删除元素1：\n");
    t1 = delTable(t1, 1);
    displayTable(t1);

    printf("在第2的位置插入元素5：\n");
    t1 = addTable(t1, 5, 2);
    displayTable(t1);

    printf("查找元素3的位置：\n");
    int add = selectTable(t1, 3);
    printf("%d\n", add);
    
    printf("将元素3改为6：\n");
    t1 = amendTable(t1, 3, 6);
    displayTable(t1);

    return 0;
}

table initTable() 
{
    table t;
    t.head = (int*) malloc(SIZE * sizeof(int)); // //构造一个空的顺序表，动态申请存储空间
    if (!t.head) {
        printf("初始化失败");
        exit(0);
    }
    t.length = 0;
    t.size = SIZE;
    return t;
}

// 输出顺序表中元素的函数
void displayTable(table t) 
{
    for (int i=0; i<t.length; i++) {
        printf("%d", t.head[i]);
    }
    printf("\n");
}


// 插入函数，elem 为插入的元素，add 为插入到顺序表的位置
table addTable(table t, int elem, int add)
{
    // 检测参数，插入的位置不能超过表长度加1，不能小于1
    if (add > t.length + 1 || add < 1) {
        printf("插入位置有问题\n");
        return t;
    }
    // 检测顺序表是否有多余的存储空间提供给插入的元素怒，没有则申请
    if (t.length * sizeof(int) == t.size) {
        t.head = (int *) realloc(t.head, (t.size+1)*sizeof(int));   // 态数组额外申请更多物理空间
        if (!t.head) {
            printf("存储分配失败\n");
            return t;
        }
        t.size += 1;
    }
    // 执行插入操作，将从插入位置开始的后继元素，逐个后移
    for (int i = t.length-1; i >= add-1; i--) {
        t.head[i+1] = t.head[i];
    }
    // 后移完成后，直接将所需插入元素，添加到顺序表的相应位置 
    t.head[add-1] = elem;
    t.length++;
    return t;
}

// 删除元素
table delTable(table t, int add)
{
    if (add>t.length || add <1) {
        printf("被删除元素的位置有误\n");
        return t;
    }
    // 删除操作
    for (int i=add; i<t.length; i++) {
        t.head[i-1] = t.head[i];
    }
    t.length--;
    return t;
}

// 查找元素，elem 为要查找的数据元素的值
// 顺序查找算法
int selectTable(table t, int elem)
{
    for (int i=0; i<t.length; i++) {
        if (t.head[i] == elem) {
            return i+1;
        }
    }
    return -1;
}

// 修改元素，elem 为要修改的元素，newElem 为修改后的元素
table amendTable(table t, int elem, int newElem)
{
    int add = selectTable(t, elem);
    t.head[add-1] = newElem;    
    return t;
}
