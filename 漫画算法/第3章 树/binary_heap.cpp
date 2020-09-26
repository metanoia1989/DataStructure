#include <iostream>
#include <algorithm>

/**
 * binary heap 二叉堆
 * 操作：插入节点、删除节点、构建二叉堆
 * 插入节点，在堆最后的位置插入节点，与其父节点的值比较，不断进行上浮操作。
 * 删除节点，删除堆的根节点，将堆的最后一个节点补到根节点，然后与左右子节点比较，不断进行下沉操作。
 * 构建二叉堆，把一个无序的完全二叉树调整为二叉堆，从最后一个非叶子节点开始，让所有非叶子节点依次下沉。   
 * 
 * 二叉堆的底层借助数组来实现，父节点的下标为parent，则左子节点的下标为 2*parent+1，右子节点下标为 2*parent+2。
 */ 

/* 下面的代码只涉及到最小堆的构建 */

template<typename T>
void swap(T& t1, T& t2)
{
    T temp = std::move(t1);
    t1 = std::move(t2);
    t2 = std::move(temp);
}


/** 
 * 上浮调整，比较子节点与父节点的大小，用于插入节点时使用
 * 
 * @param int arr[]  待调整的堆
 * @param int size 堆的大小
 */ 
void upAdjust(int arr[], int size)
{
    int childIndex = size - 1;
    int parentIndex = (childIndex - 1) / 2;
    // 子节点小于父节点的值，则上浮
    while (childIndex > 0 && arr[childIndex] < arr[parentIndex]) {
        swap(arr[childIndex], arr[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

/** 
 * 下沉调整，比较父节点与左右节点的大小，用于删除节点时使用
 * 
 * @param int arr[]  待调整的堆
 * @param int size 堆的大小
 * @param int parentIndex 要下沉的父节点
 */ 
void downAdjust(int arr[], int size, int parentIndex)
{
    int smallest = parentIndex;

    // 比较父节点与左右子节点的大小，父节点不是最小则进行交换值，不断下沉迭代
    do {
        int leftChild = 2 * smallest + 1;
        int rightChild = 2 * smallest + 2;

        if (leftChild < size && arr[leftChild] < arr[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < size && arr[rightChild] < arr[smallest]) {
            smallest = rightChild;
        }
        if (smallest != parentIndex) {
            swap(arr[smallest], arr[parentIndex]);
            parentIndex = smallest;
        }
    } while (smallest != parentIndex);
}
/**
 * 输出打印一个数组
 * 
 * @param  {int []} arr 
 */
void printArray(int arr[], size_t size)
{
    std::cout << "数组输出：";
    for (int i=0; i<size; i++)  {
        std::cout << arr[i] << ", "; 
    }   
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    // 插入一个元素，上浮操作
    int arr[] = { 1, 3, 2, 6, 5, 7, 8, 9, 10, 0};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, arr_size);
    upAdjust(arr, arr_size);
    printArray(arr, arr_size);

    int arr2[] = { 14, 3, 2, 6, 5, 7, 8, 9, 10 };
    int arr_size2 = sizeof(arr2) / sizeof(arr2[0]);
    printArray(arr2, arr_size2);
    downAdjust(arr2, arr_size2, 0);
    printArray(arr2, arr_size2);
    // 删除一个元素，下沉操作

    return 0;
}
