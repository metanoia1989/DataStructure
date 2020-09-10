// 中序遍历，非递归，栈实现

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TElemType int

// 构造节点的结构体
typedef struct BiTNode {
    TElemType data; // 数据域
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

int top = -1;   // 时刻表示栈顶元素所在位置

// 创建二叉树
void CreateBiTree(BiTree *T);   
// 模拟操作节点元素，输出节点本身的数值
void displayElem(BiTNode *elem);
// 进栈函数
void push(BiTNode **a, BiTNode *elem);
// 弹栈函数
void pop();
// 拿到栈顶元素
BiTNode* getTop(BiTNode **a);
// 中序遍历
void InOrderTraverse(BiTree Tree);
void InOrderTraverse2(BiTree Tree);

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("中序遍历栈实现：\n");
    InOrderTraverse(Tree);
    printf("\n中序遍历另一种实现：\n");
    InOrderTraverse2(Tree);
}

// 创建二叉树
void CreateBiTree(BiTree *T)   
{
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));

    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;

    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;

    (*T)->rchild->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;

    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

// 模拟操作节点元素，输出节点本身的数值
void displayElem(BiTNode *elem)
{
    printf("%d", elem->data);
}

// 进栈函数
void push(BiTNode **a, BiTNode *elem)
{
    a[++top] = elem;
}

// 弹栈函数
void pop()
{
    if (top == -1) {
        return;
    }
    top--;
}

// 拿到栈顶元素
BiTNode* getTop(BiTNode **a)
{
    return a[top];
}

// 中序遍历非递归算法
void InOrderTraverse(BiTree Tree)
{
    BiTNode* a[20]; // 定义一个顺序栈
    BiTNode *p; // 临时指针
    push(a, Tree);   // 根节点进栈
    while (top != -1) {
        while ((p = getTop(a)) && p) {   // 栈顶元素不能为空
            push(a, p->lchild); // 将该节点的左孩子进栈，为NULL也进栈
        }
        pop(); // 跳出循环，栈顶元素为NULL，将NUL出栈
        if (top != -1) {
            p = getTop(a);  // 取栈顶元素
            pop();
            displayElem(p); // 调用节点的操作函数
            push(a, p->rchild); 
        }
    }
}

// 中序遍历由一种实现
void InOrderTraverse2(BiTree Tree)
{
    BiTNode* a[20]; // 定义一个顺序栈
    BiTNode *p; // 临时指针
    p = Tree;
    // 当 p 为 NULL 或者栈为空时，树遍历完成
    while (p || top != -1) {
        if (p) { // 如果 p 不为NULL，将其压栈并遍历其左子树
            push(a, p);
            p = p->lchild;
        } else { // 如果为NULL，左子树遍历完成，需要遍历上一层节点的右子树
            p = getTop(a);  // 取栈顶元素
            pop();
            displayElem(p); // 调用节点的操作函数
            p = p->rchild;
        }
    }
}