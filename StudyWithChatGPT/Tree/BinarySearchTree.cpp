#include <iostream>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
    // 没有这一行，直接运行错误 
    // terminated by signal SIGSEGV (Address boundary error)
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    destroyTree(root);
}

void BinarySearchTree::insert(int key)
{
    if (search(key)) {
        return;
    }

    if (root == nullptr) {
        Node* node = new Node(key);
        root = node;
        return;
    }
    insertNode(root, key);

}

bool BinarySearchTree::search(int key)
{
    Node* node = searchNode(root, key);
    return node != nullptr;
}

void BinarySearchTree::remove(int key)
{
    removeNode(root, key);
}

void BinarySearchTree::destroyTree(Node *node)
{
    if (node == nullptr) {
        return;
    }

    destroyTree(node->left);
    destroyTree(node->right);

    delete node;
    node = nullptr;
}

Node *BinarySearchTree::getRoot()
{
    return root;
}

Node *BinarySearchTree::insertNode(Node *node, int key)
{
    if (node == nullptr) {
        node->key = key;
        return node;
    }

    if (key < node->key) {

        if (node->left == nullptr) {
            node->left = new Node(key);
            return node->left;
        } 

        return insertNode(node->left, key);
    } 

    if (key > node->key) {

        if (node->right == nullptr) {
            node->right = new Node(key);
            return node;
        }
        return insertNode(node->right, key);
    }

    return nullptr;
}

Node *BinarySearchTree::searchNode(Node *node, int key)
{
    if (node == nullptr) {
        return nullptr;
    }

    if (node->key == key) {
        return node;
    }

    if (key < node->key) {
        return searchNode(node->left, key); 
    } else {
        return searchNode(node->right, key); 
    }
}

Node *BinarySearchTree::removeNode(Node *node, int key)
{
    if (node == nullptr) {
        return nullptr;
    }

    // 如果要删除的键值等于当前节点的键值，执行以下操作:
    // 如果当前节点没有左子树或右子树，直接删除当前节点，并返回相应的子树（如果有的话）。
    // 如果当前节点有左子树和右子树，找到当前节点右子树中的最小节点（即右子树中的最左节点）或左子树中的最大节点（即左子树中的最右节点）。
    // 将该最小或最大节点的键值赋给当前节点，并在相应子树中递归调用 removeNode 方法，删除该最小或最大节点。
    if (key < node->key) {
        node->left = removeNode(node->left, key);
    } 
    else if (key > node->key) { 
        node->right = removeNode(node->right, key);
    } 
    else {
        // 找到了要删除的节点
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        }
        // 删除的节点只有右子树， 返回右子树的根节点
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        // 删除的节点只有左子树，返回左子树的根节点
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            // 节点左右子树都存在，找到右子树最小节点，替换当前节点
            Node* minNode = findMin(node->right);
            node->key = minNode->key;
            // 删除右子树的最小节点，搜索树只需要这个最小节替换当前节点即可，效率很高 
            node->right = removeNode(node->right, minNode->key);
        }
    }

    return node;
}

Node *BinarySearchTree::findMin(Node *node)
{
    if (node == nullptr) {
        return nullptr;
    }
    if (node->left == nullptr) {
        return node;
    }

    return findMin(node->left);
}


Node *BinarySearchTree::findMax(Node *node)
{
    if (node == nullptr) {
        return nullptr;
    }
    if (node->right == nullptr) {
        return node;
    }

    return findMax(node->right);
}
