#include <iostream>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
    int height;
} Node;


/**
 * 创建新的节点
 */ 
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->height = 0;
    return temp;
}

/**
 * 检测两个值中的最大值
 */ 
int max(int i, int j)
{
    return i > j ? i : j;
}

/**
 * 返回节点的高度
 */ 
int height(Node *p)
{
    return p == nullptr ? -1 : p->height;
}

/** 
 * 单左旋
 */ 
Node *leftLeftRotn(Node *p)
{
    Node *q = new Node;
    q = p->left;
    p->left = q->right;
    q->right = p;

    p->height = max(height(p->left), height(p->right)) + 1;
    q->height = max(height(q->left), p->height) + 1;

    return q;
}

Node *rightRightRotn(Node *p)
{
    Node *q = new Node;
    q = p->right;
    p->right = q->left;
    q->left = p;
    p->height = max(height(p->left), height(p->right)) + 1;
    q->height = max(height(q->right), p->height) + 1;

    return q;
}

/** 
 * 双旋之LR
 */ 
Node *leftRightRotn(Node *p)
{
    p->left = rightRightRotn(p->left);
    p = leftLeftRotn(p);
    return p;
}

/** 
 * 双旋之RL
 */ 
Node *rightLeftRotn(Node *p)
{
    p->right = leftLeftRotn(p->right);
    p = rightRightRotn(p);
    return p;
}

Node *balance(Node *p)
{
    int bFactor, hL, hR;
    Node *pLeft, *pRight;

    if (!p->left) {
        hL = 0;
    } else {
        hL = p->left->height + 1;
    }
    if (!p->right) {
        hR = 0;
    } else {
        hR = p->right->height + 1;
    }
    bFactor = hL - hR;

    if (bFactor < 2 && bFactor > -2) {
        return p;
    } else if (bFactor == 2) {
        pLeft = p->left;

        if (height(pLeft->left) > height(pLeft->right)) {
            return leftLeftRotn(p);
        } else {
            return leftRightRotn(p);
        }
    } else {
        pRight = p->right;
        if (height(pRight->right) > height(pRight->left)) {
            return rightRightRotn(p);
        } else {
            return rightLeftRotn(p);
        }
    }
}

/** 
 * 插入新节点
 */ 
Node *insert(Node *p, Node *newNode)
{
    if (!p) {
        printf("Key %d\tinserted\n", newNode->key);
        return newNode;
    }
    if (newNode->key > p->key) {
        p->right = insert(p->right, newNode);
        if (!(p->right)) {
            p->right = newNode;
        }
    } else {
        p->left = insert(p->left, newNode);
        if (!(p->left)) {
            p->left = newNode;
        }
    }
    p->height = max(height(p->left), height(p->right)) + 1;
    p = balance(p);
    return p;
}

int main(int argc, char const *argv[])
{
    Node *root = nullptr;

    printf("RL Rotation - \n");
    root = insert(root, newNode(50));
    root = insert(root, newNode(40));
    root = insert(root, newNode(45)); // 需要进行 RL Rotation
    printf("after Rotation root of tree - %d\n", root->key);

    printf("RR Rotation - \n");
    root = insert(root, newNode(30));
    root = insert(root, newNode(25)); // 需要进行 RR Rotation
    printf("right of left child of root - %d\n", root->left->right->key);

    printf("LL Rotation - \n");
    root = insert(root, newNode(60));
    root = insert(root, newNode(80)); // 需要进行 LL Rotation
    printf("left of right child of root - %d\n", root->right->left->key);

    printf("RL Rotation - \n");
    root = insert(root, newNode(70));
    root = insert(root, newNode(90));
    root = insert(root, newNode(65)); // 需要进行 RL Rotation
    printf("right child of root - %d\n", root->right->key);

    return 0;
}
