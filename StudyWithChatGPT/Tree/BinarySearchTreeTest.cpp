#include "BinarySearchTree.h"
#include "functions.hpp"

int main() {
    BinarySearchTree bst;

    // 插入键值对 
    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);


    // 输出当前结构 
    printBinarySearchTree(bst.getRoot());

    // 搜索键值对 
    std::cout << "Search 6: " << (bst.search(6) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 11: " << (bst.search(11) ? "Found" : "Not Found") << std::endl;

    // 删除键值对 
    bst.remove(6);
    bst.remove(10);

    // 输出当前结构 
    printBinarySearchTree(bst.getRoot());

    // 搜索键值对 
    std::cout << "Search 6: " << (bst.search(6) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 10: " << (bst.search(10) ? "Found" : "Not Found") << std::endl;

    return 0;
}