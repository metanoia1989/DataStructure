#include <iostream>

//***************************************************************
// 快速排序 
// 随机选择一个基准元素，将比基准元素大的元素移动到一遍， 
// 将比基准元素小的元素移动到另一边，从而把数列拆解成两个部分
// 每一部分在下一轮分别拆成两部分，直到不可再分为止
//***************************************************************

void quickSort(int arr[], int startIndex, int endIndex);
int partition(int arr[], int startIndex, int endIndex);
void printArr(int arr[], int size);

int main(int argc, char const *argv[])
{
    int arr[] = { 4, 4, 6, 5, 3, 2, 8, 1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, size);
    quickSort(arr, 0, size - 1);
    printArr(arr, size);
    
    return 0;
}


/**
 * 快速排序
 *
 * @param  {int []} arr     : 要排序的数组
 * @param  {int} startIndex : 排序起始下标
 * @param  {int} endIndex   : 排序结束下标
 */
void quickSort(int arr[], int startIndex, int endIndex)
{
    // 递归结束条件：startIndex 大于或等于 endIndex 时
    if (startIndex >= endIndex) {
        return;
    }
    // 得到基准元素位置
    int pivotIndex = partition(arr, startIndex, endIndex);
    // 根据基准元素怒，分成两部分进行递归排序
    quickSort(arr, startIndex, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, endIndex);
}

/**
 * 分治（双边循环法）
 *
 * @param  {int []} arr     : 待交换的数组
 * @param  {int} startIndex : 起始下标
 * @param  {int} endIndex   : 结束下标
 * @return {int}            : 
 */
int partition(int arr[], int startIndex, int endIndex)
{
    // 取第1个位置（也可以选择随机位置）的元素作为基准元素
    int pivot = arr[startIndex];
    int left = startIndex;
    int right = endIndex;
    
    while (left != right) {
        // 控制right指针比较并左移
        while (left < right && arr[right] > pivot) {
            right--;
        }
        
        // 控制left指针比较并右移
        while (left < right && arr[left] <= pivot) {
            left++; 
        }
        
        // 交换 left 和 right 指针所指向的元素
        if (left < right) {
            int p = arr[left];
            arr[left] = arr[right];
            arr[right] = p;
        }
    }
    
    // pivot 和指针重合点交换
    arr[startIndex] = arr[left];
    arr[left] = pivot;
    
    return left;
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