#include <iostream>
#include <list>

/**
 * 二叉树遍历，递归方法
 * 忽略吞枣，代码都是有问题的，漫画算法讲思路还是可以的，但是代码不适合。   
 * 其实如果我理解了思想，不用那么多算法书，吃透一两本就可以 
 */ 
class BinaryTree
{

public:
    class TreeNode;
    
    TreeNode* createBinaryTree(std::list<int> inputList)
    {
        TreeNode *node = nullptr;
        if (!inputList.empty()) {
            int data = inputList.front();
            inputList.pop_front();
            if (data != NULL) {
                node = new TreeNode(data);
                node->leftChild = createBinaryTree(inputList);
                node->rightChild = createBinaryTree(inputList);
            }
        }
        return node;
    }
    
    /**
     * 前序遍历
     */ 
    void preOrderTraversal(TreeNode *node) {
        if (node == nullptr) {
            return;
        } 
        std::cout << node->data << ",";
        preOrderTraversal(node->leftChild);
        preOrderTraversal(node->rightChild);
    }

    /**
     * 中序遍历
     */ 
    void inOrderTraversal(TreeNode *node) {
        if (node == nullptr) {
            return;
        } 
        preOrderTraversal(node->leftChild);
        std::cout << node->data << ",";
        preOrderTraversal(node->rightChild);
    }

    /**
     * 后序遍历
     */ 
    void postOrderTraversal(TreeNode *node) {
        if (node == nullptr) {
            return;
        } 
        preOrderTraversal(node->leftChild);
        preOrderTraversal(node->rightChild);
        std::cout << node->data << ",";
    }

public:
    struct TreeNode {
        TreeNode(int value) : data(value) { }

        int data;   
        TreeNode *leftChild;
        TreeNode *rightChild;
    };
};

int main(int argc, char const *argv[])
{
    std::list<int> arr = {
        3, 2, 9, 10, 8, 4 
    };
    BinaryTree tree;
    auto root = tree.createBinaryTree(arr);
    std::cout << "前序遍历: ";
    tree.preOrderTraversal(root);

    std::cout << std::endl << "中序遍历: ";
    tree.inOrderTraversal(root);

    std::cout << std::endl << "后序遍历: ";
    tree.postOrderTraversal(root);

    return 0;
}
