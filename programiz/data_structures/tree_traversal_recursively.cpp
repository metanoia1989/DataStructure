#include <iostream>
#include <queue>

/**
 * DFS - Depth First Search
 * inorder 中序遍历, preorder 前序遍历, postorder 后续遍历
 * 
 * BFS - Breadth First Search
 * levelOrder 层序遍历
 */ 
template <typename T>
struct TreeNode {
    TreeNode(T data) {
        key = data;
        leftChild = nullptr;
        rightChild = nullptr;
    };

    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
    T key;
};

/**
 * 根据层序遍历的数组值构建二叉树
 * @param  {T []} arr     : 输入数组
 * @param  {int} int      : 要插入的元素索引
 * @param  {int} size     : 数组长度
 * @return {TreeNode<T>}  : 
 */
template <typename T>
TreeNode<T>* createBinaryTree(T arr[], int i, int size)
{
    TreeNode<T>* node = nullptr;
    if (i < size) {
        node = new TreeNode<T>(arr[i]);
        node->leftChild = createBinaryTree(arr, 2*i+1, size);
        node->rightChild = createBinaryTree(arr, 2*i+2, size);
    }
    return node;
}


/**
 * 前序遍历
 * 
 * @param  {TreeNode<T>*} node : 
 */
template <typename T>
void preOrder(TreeNode<T>* node)
{
    if (node != nullptr) {
        std::cout << node->key << "->";
        preOrder(node->leftChild);
        preOrder(node->rightChild);
    }
}

/**
 * 中序遍历
 * 
 * @param  {TreeNode<T>*} node : 
 */
template <typename T>
void inOrder(TreeNode<T>* node)
{
    if (node != nullptr) {
        inOrder(node->leftChild);
        std::cout << node->key << "->";
        inOrder(node->rightChild);
    }
}

/**
 * 后续遍历
 * 
 * @param  {TreeNode<T>*} node : 
 */
template <typename T>
void postOrder(TreeNode<T>* node)
{
    if (node != nullptr) {
        postOrder(node->leftChild);
        postOrder(node->rightChild);
        std::cout << node->key << "->";
    }
}

/**
 * 层序遍历
 * 
 * @param  {TreeNode<T>*} node : 
 */
template <typename T>
void levelOrder(TreeNode<T>* node)
{
    std::queue<TreeNode<T>*> queue;
    queue.push(node);
    while (!queue.empty()) {
        auto next = queue.front();
        queue.pop();
        std::cout << next->key << "->";
        if (next->leftChild != nullptr) {
            queue.push(next->leftChild);
        }
        if (next->rightChild != nullptr) {
            queue.push(next->rightChild);
        }
    }
}

int main(int argc, char const *argv[])
{
    /**
     *         1 
     *       2   3 
     *     4  5  6 7
     *   7  8   8
     */ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 7, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    TreeNode<int>* node = createBinaryTree(arr, 0, size);

    std::cout << "前序遍历：";
    preOrder(node);

    std::cout << "\n中序遍历：";
    inOrder(node);

    std::cout << "\n后序遍历：";
    postOrder(node);

    std::cout << "\n层序遍历：";
    levelOrder(node);

    // 输出结果
    // 前序遍历：1->2->4->7->8->5->8->3->6->7->
    // 中序遍历：7->4->8->2->8->5->1->6->3->7->
    // 后序遍历：7->8->4->8->5->2->6->7->3->1->
    // 层序遍历：1->2->3->4->5->6->7->7->8->8->

    return 0;
}

