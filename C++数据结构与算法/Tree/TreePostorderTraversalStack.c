// 后序遍历，非递归，栈实现

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TElemType int

// 构造节点的结构体
typedef struct BiTNode {
    TElemType data; // 数据域
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 为每个节点添加一个标志位
typedef struct SNode {
    BiTree p;
    int tag;
} SNode;

int top = -1;   // 时刻表示栈顶元素所在位置

// 创建二叉树
void CreateBiTree(BiTree *T);   
// 模拟操作节点元素，输出节点本身的数值
void displayElem(BiTNode *elem);
// 进栈函数
void push(SNode *a, SNode sdata);
// 弹栈函数
void pop();
// 拿到栈顶元素
SNode getTop(SNode *a);
// 后序遍历
void PostOrderTraverse(BiTree T);

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("后序遍历：\n");
    PostOrderTraverse(Tree);
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
void push(SNode *a, SNode sdata)
{
    a[++top] = sdata;
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
SNode getTop(SNode *a)
{
    return a[top];
}

// 后序遍历非递归算法
void PostOrderTraverse(BiTree Tree)
{
    SNode a[20];    // 定义一个顺序栈
    BiTNode *p; // 临时指针
    int tag;
    SNode sdata;
    p = Tree;
    while (p || top != -1) {
        while (p) {
            // 为该节点入栈做准备
            sdata.p = p;
            sdata.tag = 0;  // 遍历是左孩子，设置标志位为0
            push(a, sdata); // 压栈
            p = p->lchild;  // 以该节点为根节点，遍历左孩子
        }
        sdata = getTop(a); // 取栈顶元素
        pop();  // 栈顶元素出栈
        p = sdata.p;
        tag = sdata.tag;
        if (tag == 0) { // 如果 tag == 0，说明节点还没有遍历它的右孩子
            sdata.p = p;
            sdata.tag = 1;
            push(a, sdata); // 更改该节点的标志位，重新入栈
            p = p->rchild;  // 以该及诶单的右孩子为根节点，重复循环
        } else {    // 如果取出来的栈顶元素 tag==1，说明此节点左右子树都循环遍历完了，可以调用操作函数
            displayElem(p);
            p = NULL;
        }
    }
}