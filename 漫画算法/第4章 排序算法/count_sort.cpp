#include <iostream>
#include <algorithm>
#include <array>

//***************************************************************************
// 计数排序的缺点：
// 1. 当数列最大和最小值差距过大时，需要创建很长的数组，严重浪费空间，时间复杂度也会随之提高    
// 2. 当数列元素不是整数时，为小数时就无法创建对应的统计数组，无法进行计数排序
//***************************************************************************

void print_arr(int arr[], int size);

/**
 * 计数排序说明
 * 将数组元素映射为计数数组的下标，遇到相关的元素则计数数组的对应值加1，
 * 然后根据计数数组的值，输出下标即可。 
 */ 
void count_sort(int arr[], int size)
{
    // 获取列的最大值 
    int max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // 根据数列最大值确定统计数组的长度
    int *countArr = new int[max+1] {};
    
    // 遍历数列，填充统计数组
    for (size_t i = 0; i < size; i++) {
        countArr[arr[i]]++;
    }
    
    // 遍历统计数组，构建排序好的数组
    int index = 0;
    for (size_t i = 0; i < max+1; i++) {
        int count = countArr[i];     
        for (size_t j = 0; j < count; j++) {
            arr[index] = i; 
            index++;
        }
    }
}

/**
 * 计数排序优化版，解决排序数组最大值最小值差别不大，但是最大值很大的问题
 * 在这样的情况还根据最大值大小来创建计数数组为非常浪费空间
 * 根据最大值、最小值的差值来创建计数数组，最小值作为偏移量
 * 统计排序数组值的数量时，将值减去偏移量，输出时再加上偏移量   
 */
void count_sort_shift(int arr[], int size)
{
    // 获取列的最大值 
    int max = arr[0];
    int min = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min) 
            min = arr[i];
    }

    // 根据数列最大值确定统计数组的长度
    int countSize = max - min + 1;
    int *countArr = new int[countSize] {};
    
    // 遍历数列，填充统计数组
    for (size_t i = 0; i < size; i++) {
        countArr[arr[i] - min]++;
    }
    
    // 遍历统计数组，构建排序好的数组
    int index = 0;
    for (size_t i = 0; i < countSize; i++) {
        int count = countArr[i];     
        for (size_t j = 0; j < count; j++) {
            arr[index] = i + min; 
            index++;
        }
    }
}

/**
 * 优化版的计数排序，排序后原有值相同的元素其顺序不变   
 * 生成计数数组之后，从计数数组的第2个元素开始，每个元素都加上前面所有元素之和      
 * 这样计数数组存储的元素值等于相应整数的最终排序位置的序号 
 */ 
void count_sort_stable(int arr[], int size)
{
    // 获取列的最大值 
    int max = arr[0];
    int min = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min) 
            min = arr[i];
    }

    // 根据数列最大值确定统计数组的长度
    int countSize = max - min + 1;
    int *countArr = new int[countSize] {};
    

    // 遍历数列，填充统计数组
    for (size_t i = 0; i < size; i++) {
        countArr[arr[i]-min]++;
    }
    
    // 计数数组做变形处理，后面的元素等于前面的元素之和
    for (size_t i = 1; i < countSize; i++) { // 从1开始，因为会减1
        countArr[i] += countArr[i-1];
    }
    
    // 因为计数数组已经变形了，所以索引值不再是正确的次数了 
    // 遍历统计数组，构建排序好的数组
    // 直接遍历原始数组，然后从计数数组中获取排序好后的索引 
    int index = 0;
    int *sortedArr = new int[size];
    for (size_t i = 0; i < size ; i++) {
        int value = arr[i]; // 元素的值
        int num = countArr[value-min] - 1; // 排序后的索引
        sortedArr[num] = value;
        countArr[value-min]--; 
    }

    // 将数组拷贝回去
    for (size_t i = 0; i < size ; i++) {
        arr[i] = sortedArr[i];
    }
    delete [] sortedArr;
}


void print_arr(int arr[], int size)
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

int main(int argc, char const *argv[])
{
    int arr[] = { 4, 4, 6, 5, 3, 2, 8, 1, 7, 5, 6, 0, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, size);
    count_sort(arr, size);
    std::cout << "count sort后-->";
    print_arr(arr, size);

    int newarr[] = { 7, 5, 6, 10 };
    int newsize = sizeof(newarr) / sizeof(newarr[0]);
    print_arr(newarr, newsize);
    count_sort_shift(newarr, newsize);
    std::cout << "count sort shift后-->";
    print_arr(newarr, newsize);

    int countarr[] = { 95, 94, 91, 98, 99, 90, 99, 93, 91, 92 };
    int countsize = sizeof(countarr) / sizeof(countarr[0]);
    print_arr(countarr, countsize);
    count_sort_stable(countarr, countsize);
    std::cout << "count sort stable后-->";
    print_arr(countarr, countsize);
    return 0;
}

