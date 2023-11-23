#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "BinarySearchTree.h"
#include <string>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <algorithm>
#include <vector>

int getHeight(Node* root) {
    if (root == nullptr) return 0;
    return std::max(getHeight(root->left), getHeight(root->right)) + 1;
}

void printTreeUtil(Node* root, int start, int end, int level, std::vector<std::vector<std::string>>& output) {
    if (root == nullptr) return;

    int pos = start + (end - start) / 2; // 找到开始和结束之间的中点位置
    output[level][pos] = std::to_string(root->key);

    // 递归地打印左右子树
    if (root->left) {
        output[level + 1][pos - 1] = "/"; // 将斜线放在父节点的左下方
        printTreeUtil(root->left, start, pos, level + 2, output);
    }
    if (root->right) {
        output[level + 1][pos + 1] = "\\"; // 将反斜线放在父节点的右下方
        printTreeUtil(root->right, pos, end, level + 2, output);
    }
}


void printBinarySearchTree(Node* root) {
    int treeHeight = getHeight(root);
    int width = pow(2, treeHeight) - 1;
    std::vector<std::vector<std::string>> output(2 * treeHeight, std::vector<std::string>(width, " "));

    printTreeUtil(root, 0, width, 0, output);

    // 打印
    for (const auto& line : output) {
        for (const auto& val : line) {
            std::cout << val;
        }
        std::cout << std::endl;
    }
}

#endif

