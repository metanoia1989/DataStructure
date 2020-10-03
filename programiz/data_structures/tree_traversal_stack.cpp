#include <iostream>
#include <stack>

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
    if (false) {
        // 一种遍历方式
        std::stack<TreeNode<T>*> stack; 
        auto curr = node;
        if (curr != nullptr) {
            stack.push(curr);
            while (!stack.empty()) {
                curr = stack.top();
                stack.pop();
                std::cout << curr << "->";
                if (curr->rightChild != nullptr) {
                    stack.push(curr->rightChild);
                }
                // left 后入栈，先出栈
                if (curr->leftChild != nullptr) {
                    stack.push(curr->leftChild);
                }
            
            }
        }
    } else {
        std::stack<TreeNode<T>*> stack;
        auto curr = node;
        while (curr != nullptr || !stack.empty()) {
            // 先输出节点，然后迭代访问节点的左孩子，并入栈
            while (curr != nullptr) {
                std::cout << curr->key << "->";
                stack.push(curr);
                curr = curr->leftChild;
            }
            // 节点左孩子访问完毕，弹出栈顶节点，访问节点右孩子
            curr = stack.top(); 
            curr = curr->rightChild;
            stack.pop();
        }
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
    std::stack<TreeNode<T>*> stack;
    auto curr = node;
    while (curr != nullptr || !stack.empty()) {
        // 先输出节点，然后迭代访问节点的左孩子，并入栈
        while (curr != nullptr) {
            stack.push(curr);
            curr = curr->leftChild;
        }
        // 节点左孩子访问完毕，弹出栈顶节点，访问节点右孩子
        curr = stack.top();
        std::cout << curr->key << "->";
        curr = curr->rightChild;
        stack.pop();
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
    if (false) {
        // 两个栈解决问题   
        std::stack<TreeNode<T>*> stackIn, stackOut;
        stackIn.push(node);
        while (!stackIn.empty()) {
            auto curr = stackIn.top();
            stackIn.pop();
            stackOut.push(curr);
            if (curr->leftChild != nullptr) {
                stackIn.push(curr->leftChild);
            }
            // 后入栈，先出栈。会先进入stackOut
            if (curr->rightChild != nullptr) {
                stackIn.push(curr->rightChild);
            }
        }
        while (!stackOut.empty()) {
            auto curr = stackOut.top();
            std::cout << curr->key << "->";
            stackOut.pop();
        }
    } else {
        // 一个栈解决问题   
        std::stack<TreeNode<T>*> stack;
        stack.push(node);
        // 太难了，看不懂，等水平好点了再来看，先做做简单的数据结构好了

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

    // 输出结果
    // 前序遍历：1->2->4->7->8->5->8->3->6->7->
    // 中序遍历：7->4->8->2->8->5->1->6->3->7->

    return 0;
}
