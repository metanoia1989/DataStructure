// 后序遍历，递归实现

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TElemType int

// 构造节点的结构体
typedef struct BiTNode {
    TElemType data; // 数据域
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 创建二叉树
void CreateBiTree(BiTree *T);   
// 模拟操作节点元素，输出节点本身的数值
void displayElem(BiTNode *elem);
// 后序遍历
void PostorderTraverse(BiTree T);

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("后序遍历：\n");
    PostorderTraverse(Tree);
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

// 后序遍历
void PostorderTraverse(BiTree T)
{
    if (T) {
        PostorderTraverse(T->lchild);    // 访问该节点的左孩子
        PostorderTraverse(T->rchild);    // 访问该节点的右孩子
        displayElem(T); // 调用操作节点数据的函数方法
    }
    // 如果节点为空，返回上一层
    return;
}