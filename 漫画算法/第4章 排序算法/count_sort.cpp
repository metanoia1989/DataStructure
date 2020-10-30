#include <iostream>

/**
 * 计数排序说明
 * 
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
    std::cout << std::endl;
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
    print_arr(arr, size);

    return 0;
}

