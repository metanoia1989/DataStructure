#include <stdio.h>
#include <stdlib.h>
#define TElemType int

typedef struct BiTNode {
    TElemType data; // 数据域
    struct BiTNode *lchild, *rchild; // 左右子节点指针
} BiTNode, *BiTree;

void CreateBiTree(BiTree *T);

int main()
{
    BiTree Tree;
    CreateBiTree(&Tree);
    printf("%d", Tree->lchild->lchild->data);
    return 0;
}

void CreateBiTree(BiTree *T)
{
    *T = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->rchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = NULL;
    (*T)->rchild->rchild= NULL;
    (*T)->lchild->lchild = (BiTNode*)malloc(sizeof(BiTNode));
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->rchild = NULL;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}