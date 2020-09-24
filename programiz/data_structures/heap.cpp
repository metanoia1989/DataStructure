#include <iostream>

/**
 * heap 堆
 * 二叉堆是特殊的完全二叉树，binary heap is a complete binary tree that satisfies the heap property.
 * 最大堆 min-heap：任何一个父节点的值，都大于或等于其左右子节点的值
 * 最小堆 max-heap：任意一个父节点的值，都小于或等于其左右子节点的值
 * heap 最关键的是heapify，构建heap、插入节点、删除节点，都要经过heapify。
 * 堆化的关键在于元素交换，从根节点向下，比较父节点与子节点的大小，不断地交换，让元素上浮。 
 */ 
 class Heap {

 };