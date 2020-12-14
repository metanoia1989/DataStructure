#include <iostream>

//*****************************************************
// 堆排序说明
// 堆排序算法的时间复杂度分析
// 1. 把无序数组构建成二叉堆，O(n)
// 2. 循环删除堆顶元素，将元素移动到集合尾部【已排序区间】
// 调整堆产生新的堆顶。共 n-1 次循环，每次的复杂度为 logn
// 整体的时间负责度为 O(nlogn)  
//*****************************************************


void downAdjust(int arr[], int parentIndex, int size);
void heapSort(int arr[], int size);

int main(int argc, char const *argv[])
{


    return 0;
}


/**
 * 堆节点下沉操作
 *
 * @param  {int []} arr      : 待调整的堆
 * @param  {int} parentIndex : 要下沉的父节点
 * @param  {int} size        : 堆得有效大小
 */
void downAdjust(int arr[], int parentIndex, int size)
{
    int temp = arr[parentIndex]; // 保存父节点的值 
    int childIndex = 2 * parentIndex + 1;
    while (childIndex < size) { // 迭代处理每个父节点
         
    }
}

/**
 * 堆排序 升序
 *
 * @param  {int []} arr : 待调整的堆
 * @param  {int} size   : 堆的初始大小
 */
void heapSort(int arr[], int size)
{
    
}