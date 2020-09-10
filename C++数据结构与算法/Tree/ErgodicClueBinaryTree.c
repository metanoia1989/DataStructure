// 遍历线索二叉树

#include <stdio.h>
#include <stdlib.h>
#define TElemType char // 宏定义，节点中数据域的类型

// 枚举，Link为0，Thread为1
typedef enum {
    Link,
    Thread
} PointerTag;

// 节点结构构造
typedef struct BiThrNode {
    TElemType data; // 数据域
    struct BiThrNode *lchild, *rchild;  // 左孩子、右孩子指针域
    PointerTag Ltag, Rtag;  // 标志域，枚举类型
} BiThrNode, *BiThrTree;

BiThrTree pre = NULL;

// 前序初始化二叉树
void CreateTree(BiThrTree *tree);
// 中序对二叉树进行线索化
void InThreading(BiThrTree p);
// 中序遍历线索二叉树
void InOrderThraverse_Thr(BiThrTree p);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

// 前序初始化二叉树
// 中序和后续只需要改变赋值语句的位置即可
void CreateTree(BiThrTree *tree)
{
    char data;
    scanf("%c", &data);
    if (data != '#') {
        *tree = (BiThrNode*)malloc(sizeof(BiThrNode));
        if (!(*tree)) {
            printf("申请节点空间失败");
            return;
        } else {
            (*tree)->data = data;   // 采用前序遍历方式初始化二叉树
            (*tree)->Ltag = Link;
            (*tree)->Rtag = Link;
            CreateTree(&(*tree)->lchild);   // 初始化左子树
            CreateTree(&(*tree)->rchild);   // 初始化右子树
        }
    } else {
        *tree = NULL;
    }
}

// 中序对二叉树进行线索化
void InThreading(BiThrTree p)
{
    // 如果当前节点存在
    if (p) {
        InThreading(p->lchild); // 递归当前节点的左子树，进行线索化
        // 如果当前节点没有左孩子，左标志位设为1，左指针指向上一节点 pre
        if (!p->lchild) {
            p->Ltag = Thread;
            p->lchild = pre;
        }
        // 如果 pre 没有右孩子，右标志位设为1，右指针域指向当前节点
        if (pre && !pre->rchild) {
            pre->Rtag = Thread;
            pre->rchild = p;
        }
    } 
}

// 中序遍历线索二叉树
void InOrderThraverse_Thr(BiThrTree p)
{

}