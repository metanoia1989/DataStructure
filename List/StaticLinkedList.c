#include <stdio.h>
#define maxSize 6

typedef struct {
    int data;   // 数据域
    int cur;    // 游标
} component;

// 将结构体数组中所有分量链接到备用链表中
void reserveArr(component *array);
// 初始化静态链表
int initArr(component *array);
// 输出函数
void displayArr(component *array, int body);
// 向链表中插入数据
void insertArr(component *array, int body, int add, char a);
// 静态链表删除数据
void deleArr(component *array, int body, char a);
// 静态链表查找元素
int selectElem(component *array, int body, char elem);
//  静态链表修改元素
void amendElem(component *array, int body, char oldElem, char newElem);
// 从备用链表上摘下空闲节点的函数
int mallocArr(component *array);
//将摘除下来的节点链接到备用链表上
void freeArr(component * array,int k);

int main()
{
    component array[maxSize];
    int body = initArr(array);
    printf("静态链表为：\n");
    displayArr(array, body);

    return 0;
}

// 创建备用链表，将结构体数组中所有分量链接到备用链表中
void reserveArr(component *array)
{
    for (int i=0; i<maxSize; i++) {
        array[i].cur = i + 1; // 将每个数组分量链接到一起
        array[i].data = -1;
    }
    array[maxSize-1].cur = 0;   // 链表最后一个节点的游标值为0
}

// 初始化静态链表
int initArr(component *array)
{
    reserveArr(array);
    int body = mallocArr(array);
    // 声明一个变量吗，把它当指针使用，指向链表的最后一个节点
    // 链表为空时，与头节点重合
    int tempBody = body;
    for (int i=1; i<4; i++) {
        int j = mallocArr(array);   // 从备用链表中拿出空闲的分量
        array[tempBody].cur = j;    // 将申请的空闲分量链接在链表的最后一个节点后面
        array[j].data = i;  // 给新申请的分量的数据域初始化
        tempBody = j;   // 将指向链表最后一个节点的指针后移
    }
    array[tempBody].cur = 0;    // 新的链表最后一个节点的指针设置为0
    return body;
}

// 输出函数
void displayArr(component *array, int body)
{
    int tempBody = body;
    while (array[tempBody].cur) {
        printf("%d, %d", array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d, %d\n", array[tempBody].data, array[tempBody].cur);

}

// 提取分配空间，从备用链表上摘下空闲节点的函数，返回备用链表表头的下一个空闲节点
int mallocArr(component *array)
{
    // 若备用链表非空，则返回分配的节点下标，否则返回0
    // 当分配最后一个节点时，该节点的游标值为0
    int i = array[0].cur;
    if (array[0].cur) {
        array[0].cur = array[i].cur;
    }
    return i;
}


// 向链表中插入数据，body 链表的头节点在数组中的位置，add 插入元素的位置，a 要插入的数据
void insertArr(component *array, int body, int add, char a)
{
    int tempBody = body;  
    // 找到要插入位置的上一个节点在数组中的位置
    for (int i=0; i<add; i++) {
        tempBody = array[tempBody].cur;
    }
    int insert = mallocArr(array);  // 申请空间，准备插入
    array[insert].data = a;
    array[insert].cur = array[tempBody].cur;    // 新插入节点的游标等于其直接前驱节点的游标
    array[tempBody].cur = insert;   // 直接前驱节点的游标等于新插入节点所在数组中的下标
}

// 备用链表回收空间的函数，array 为存储数据的数组，k 表示未使用节点所在数组的下标
void freeArr(component *array, int k)
{
    array[k].cur = array[0].cur;
    array[0].cur = k;
}

// 静态链表删除元素，a 表示被删除节点中数据域存放的数据
void deleArr(component *array, int body, char a)
{
    int tempBody = body;
    // 找到被删除节点的位置
    while (array[tempBody].data != a) {
        tempBody = array[tempBody].cur;
        // 当tempBody为0时，表示链表遍历结束，说明链表没有存储该数据的节点
        if (tempBody == 0) {
            printf("链表中没有此数据");
            return;
        }
    }
    
    int del = tempBody;
    tempBody = body;
    // 找到该节点的上一个节点，做删除操作
    while (array[tempBody].cur != del) {
        tempBody = array[tempBody].cur;
    }
    // 将被删除节点的游标直接给被删除节点的上一个节点
    array[tempBody].cur = array[del].cur;
    // 回收被删除节点的空间
    freeArr(array, del);
}

// 静态链表查找元素
// 在以body作为头节点的链表中查找数据域为elem的节点在数组中的位置
int selectElem(component *array, int body, char elem)
{
    int tempBody = body;
    // 当游标值为0时，表示链表结束
    while (array[tempBody].cur != 0) {
        if (array[tempBody].data == elem) {
            return tempBody;
        } 
        tempBody = array[tempBody].cur;
    }
    return -1; // -1 表示在链表中没有找到该元素
}

// 静态链表修改元素
// 在以body作为头节点的链表中将数据域为 oldElem 的节点，数据域改为 newElem
void amendElem(component *array, int body, char oldElem, char newElem)
{
    int add = selectElem(array, body, oldElem);
    if (add == -1) {
        printf("无更改元素");
        return;
    }
    array[add].data = newElem;
}