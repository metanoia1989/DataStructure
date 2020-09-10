#include <iostream>

struct Node {
    int item; 
    Node *left;
    Node *right;
};

Node *newNode(int item) {
    Node *node = new Node();
    node->item = item;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

/** 
 * 检测一个二叉树是否是平衡二叉树
 * 平衡二叉树，任意节点的左右子树高度差不大于1  
 * 使用递归来解决，一个二叉平衡树的任意子树都是平衡二叉树。
 * 
 */ 
bool checkHeightBalance(Node *root, int *height)
{
    int leftHeight = 0, rightHeight = 0; // 左右子树高度
    bool l = false, r = false; // 左右子树是否是平衡二叉树 

    if (root == nullptr) {
        *height = 0;
        return true;
    }

    l = checkHeightBalance(root->left, &leftHeight);
    r = checkHeightBalance(root->right, &rightHeight);

    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    // 左右子树高度差大于1，则不是平衡二叉树
    if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2)) {
        return false;
    } else {
        return l && r;
    }
}

int main(int argc, char const *argv[])
{
    int height = 0;

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    if (checkHeightBalance(root, &height)) {
        std::cout << "The tree is balaced";
    } else {
        std::cout << "The tree is not balanced";
    }

    return 0;
}
