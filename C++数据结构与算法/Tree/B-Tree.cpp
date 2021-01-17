#include <iostream>

//*************************************************
// B树以及m阶多叉树的相关性质
//
// m阶多叉树，m叉树
// 每个节点都包含m个子节点和m-1个键值
// 所有节点中的键值都按照升序来排列
// 
// m阶的B树
// 1. 有的叶子节点都在同一层。
// 2. 叶子节点没有子节点也没有指向子节点的指针
// 3. 叶子节点有k一1个键，m/2≤k≤m，其中m/2向上取整
// 4. 非根叶节点有k-1个键值和k个指向子树的指针，m/2≤k≤m
// 5. 根节点到有2个子树，至多有m个子树
// 
// 以上条件让B树是半满的，宽而矮，并且平衡
//*************************************************


//*************************************************
// B树的节点类
// 存储键值的数组，大小为 m-1
// 存储指向其他节点的指针的数组，大小为m
// 节点中键值的个数
// 叶子/非叶子的标志
//*************************************************

template<typename T, int M>
class BTree;

template<typename T, int M>
class BTreeNode
{
public:
private:
    bool leaf;
    int keyTally; // 键值数量
    T keys[M-1]; // 存储键的数组
    BTreeNode *pointers[M]; // 指向其他节点的指针的数组
    friend BTree<T, M>;
};

// B树键值的查找算法
// 这个搜索我没有搞懂，我去啊
// 用的是递归的显示，如果到达了叶子节点仍然没有找到，则返回nullptr
// for(i=1; i<=node-> keyTally ＆ nade->keys[i]<keyValue; i++) ↓
// 迭代节点所有的键，两种情况下终断循环：
// 1. i > node->keyTally，找完了所有的键，值都比目标小。
// 2. node->keys[i-1]>keyValue，键值比目标值大或等于目标值。
// 
// 等于标值当前节点就是要找的节点了 poicers n-3
// 找完了所有建，此时i = node->keyTally，到最右侧子树上找
// 键值大于目标值，i-1 就是第个键的值，对应的指针节的值都是于键i的值的
template<typename T, int M>
BTreeNode<T, M> *BTreeSearch(T keyValue, BTreeNode<T, M> *node)
{
    if (node == nullptr) {
        return nullptr;
    } 
    for (int i = 1; i <= node->keyTally && node->keys[i-1] < keyValue; i++);
    if (i > node->keyTally || node->keys[i-1] > keyValue) {
        return BTreeSearch(keyValue, node->pointers[i-1]);
    } else {
        return node;
    }
}