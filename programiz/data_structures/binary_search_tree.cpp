#include <iostream>

/** 
 * 二叉查找树，搜索、添加、删除操作
 */ 

struct node {
    int value;
    struct node *left, *right;
};

struct node *newNode(int value)
{
    struct node *temp = static_cast<struct node *>(malloc(sizeof(struct node))); 
    temp->value = value;
    temp->left = temp->right = nullptr;
    return temp;
}

/** 
 * 中序遍历
 */ 
void inorder(struct node *root)
{
    if (root != nullptr) {
        // 遍历左子树
        inorder(root->left);
        // 遍历父节点
        std::cout << root->value << " -> ";
        // 遍历右子树
        inorder(root->right);
    }
}

/**
 * 插入新节点
 * 根据二叉查找树的特性，比较要插入值与根节点的大小，不断下沉，直到合适的位置
 */ 
struct node *insert(struct node *node, int value)
{
    if (node == nullptr) {
        return newNode(value); // 新节点下沉完毕
    } 
    if (value < node->value) {
        node->left = insert(node->left, value); // 新节点下沉到左子树
    } else {
        node->right = insert(node->right, value); // 新节点下沉到右子树
    }
    return node;
}

/** 
 * 查找先序遍历的后续节点，左子树的最左子节点即是最小值
 */ 
struct node *minValueNode(struct node *node)
{
    struct node *current = node;

    // 找到最左侧的叶子节点
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

/** 
 * 删除一个节点
 */ 
struct node *deleteNode(struct node *root, int value)
{
    // 如果根节点为空，则直接返回
    if (root == nullptr) {
        return root;
    }

    // 查找一个节点，然后删除掉
    if (value < root->value) {
        root->left = deleteNode(root->left, value); // 要删除的节点在左子树
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value); // 要删除的节点在右子树
    } else {
        // 当前 root 即是要删除的节点
        // 如果节点只有一个孩子，保留其子节点
        // 如果节点没有孩子，直接删除即可
        if (root->left == nullptr) {
            struct node *temp = root->right;
            free(root);
            return temp; 
        } else if (root->right == nullptr) {
            struct node *temp = root->left;
            free(root);
            return temp; 
        } 

        // 如果节点有两个孩子，拿到右子树的最小值替换当前节点值
        // 然后删除右子树的最小值
        struct node *temp = minValueNode(root->right); // 拿到
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

int main(int argc, char const *argv[])
{
    struct node *root = nullptr;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    std::cout << "二叉查找树中序遍历：";
    inorder(root);

    std::cout << "\nAfter deleting 10\n";
    root = deleteNode(root, 10);

    std::cout << "二叉查找树中序遍历：";
    inorder(root);

    return 0;
}
