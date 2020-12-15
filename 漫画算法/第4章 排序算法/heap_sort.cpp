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
void printArr(int arr[], int size);

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 3, 2, 6, 5, 7, 8, 9, 10, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, size);

    printArr(arr, size);

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
        // 如果有右孩子，且右孩子大于左孩子的值，则定位到右孩子          
        if (childIndex + 1 < size && arr[childIndex + 1] > arr[childIndex]) {
            childIndex++;
        }
        // 如果父节点大于任何一个孩子的值，则直接跳出
        if (temp >= arr[childIndex])
            break;
        arr[parentIndex] = arr[childIndex];
        parentIndex = childIndex;
        childIndex = 2 * childIndex + 1;
    }
    arr[parentIndex] = temp;
}

/**
 * 堆排序 升序
 *
 * @param  {int []} arr : 待调整的堆
 * @param  {int} size   : 堆的初始大小
 */
void heapSort(int arr[], int size)
{
    // 把无序数组构建成最大堆    
    for (int i = (size - 2) / 2; i >= 0; i--) {
        downAdjust(arr, i, size);
    }
    printArr(arr, size);
    
    // 循环删除堆定元素，移动到集合尾部，调整堆产生新的堆顶
    for (int i = size - 1; i > 0; i--) {
        // 最后一个元素和第一个元素进行交换 
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        // 下沉，调整最大堆
        downAdjust(arr, 0, i);
    }
}

/**
 * 输出数组的值
 *
 * @param  {int []} arr : 要输出的数组
 * @param  {int} size   : 数组大小
 */
void printArr(int arr[], int size)
{
    std::cout << "输出数组元素：";
    for (size_t i = 0; i < size; i++)
    {
        std::cout << arr[i];
        if (i != size - 1 ) 
            std::cout << ", ";
    }
    std::cout << std::endl;
}