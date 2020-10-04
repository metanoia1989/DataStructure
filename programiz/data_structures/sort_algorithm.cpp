#include <iostream>
#include <algorithm>
#include <iterator>
/**
 * 常用排序算法，=_= 红黑树、B树啥的太复杂的，后面的图也很复杂，我先把基础的啃完，
 * 等思维水平跟上去了，再去啃那些难点的东西。   
 * Bubble Sort 冒泡排序
 * Selection Sort 选择排序
 * Insertion Sort 插入排序
 * Merge Sort 归并排序
 * Quick Sort 快速排序
 * Counting Sort 计数排序
 * Radix Sort 基数排序
 * Bucket Sort 桶排序
 * Heap Sort 堆排序
 * Shell Sort 希尔排序
 */ 

template <typename T>
void printArray(T arr[], int size)
{
    std::cout << "数组元素为：";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
}

/**
 * Bubble sort 冒泡排序
 * 从第一个元素开始向后检测，如果后面元素比当前元素大，则进行交换操作。一轮下去，最大的元素就在最后面了。
 * 重复这个过程，大的元素都会浮到后面去，类似冒泡一样。
 * bubbleSort(array)
 *   for i <- 1 to indexOfLastUnsortedElement-1
 *       if leftElement > rightElement
 *       swap leftElement and rightElement
 * end bubbleSort
 */ 
template <typename T>
void bubbleSort(T arr[], int size)
{
    for(int step = 0; step < size - 1; step++) 
    {
        // 有序标记，每一轮的初始值都是 true，经过任何交换都设置false
        bool isSorted = true;
        for (int i = 0; i < size - step - 1; i++) 
        {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
        if (isSorted) {
            break;
        }
    }
}

/**
 * Selection Sort 选择排序
 * 
 */ 


int main(int argc, char const *argv[])
{
    int data[] = { -2, 45, 0, 11, -9 };
    int size = sizeof(data) / sizeof(data[0]);

    int dest[size];
    std::copy(std::begin(data), std::end(data), dest);
    
    std::cout << "原始数组数据：" << std::endl;
    printArray(data, size);

    std::cout << "冒泡排序后数据："<< std::endl;
    bubbleSort(dest, size);
    printArray(dest, size);

    return 0;
}

