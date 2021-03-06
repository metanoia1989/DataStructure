// 请输出节点个数:
// 10
// 请输入结点的值其双亲位于数组中的位置下标:
// R -1
// A 0
// B 0
// C 0
// D 1
// E 1
// F 3
// G 6
// H 6
// K 6
// 请输入要查询的结点值:
// C
// C的父节点为 R,存储位置下标为 0

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef char ElemType;  // 宏定义树结构中数据类型
typedef struct Snode   // 节点结构
{
    ElemType data;
    int parent;
} PNode;
typedef struct  // 树结构
{
    PNode tnode[MAX_SIZE];
    int n;  // 节点个数
} PTree;

PTree InitPNode(PTree tree);
void FindParent(PTree tree);

int main()
{
    PTree tree;
    for (int i = 0; i < MAX_SIZE; i++) {
        tree.tnode[i].data = ' ';
        tree.tnode[i].parent = 0;
    }
    tree = InitPNode(tree);
    FindParent(tree);
    return 0;    
}

PTree InitPNode(PTree tree)
{
    int i, j;
    char ch;
    printf("请输出节点个数：\n");
    scanf("%d", &(tree.n));

    printf("请输入节点的值其双亲位于数组中的位置下标：\n");
    for (i = 0; i < tree.n; i++) {
        getchar();
        scanf("%c %d", &ch, &j);
        tree.tnode[i].data = ch;
        tree.tnode[i].parent = j;
    }
    return tree;
}

void FindParent(PTree tree)
{
    char a;
    int isfind = 0;
    printf("请输入要查询的节点值：\n");
    getchar();
    scanf("%c", &a);
    for (int i = 0; i < tree.n; i++) {
        if (tree.tnode[i].data == a) {
            isfind = 1;
            int ad = tree.tnode[i].parent;
            printf("%c的父节点为%c，存储位置的下标为%d", a, tree.tnode[ad].data, ad);
            break;
        } 
    }
    if (isfind == 0) {
        printf("树中无此节点");
    }
}
