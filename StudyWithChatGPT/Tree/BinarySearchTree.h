#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

struct Node {
    int key;
    Node* left;
    Node* right;
    Node() : key(0), left(nullptr), right(nullptr) {}
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree();
    ~BinarySearchTree();

    // 向二叉搜索树中插入一个新的键值对
    void insert(int key);

    // 在二叉搜索树中搜索指定的键，如果存在则返回true，否则返回false
    bool search(int key);

    // 从二叉搜索树中删除指定的键
    void remove(int key);

    // 获取树的根节点
    Node* getRoot();

private:
    // 递归地释放整个树的内存
    void destroyTree(Node* node);

    // 递归地插入一个新节点，并返回根节点
    Node* insertNode(Node* node, int key);

    // 递归地搜索指定的节点，并返回找到的节点
    Node* searchNode(Node* node, int key);

    // 递归地删除指定的节点，并返回根节点
    Node* removeNode(Node* node, int key);

    // 找到树中的最小节点
    Node* findMin(Node* node);
};

#endif