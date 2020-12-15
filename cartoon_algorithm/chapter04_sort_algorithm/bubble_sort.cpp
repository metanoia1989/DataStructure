#include <iostream>
#include <algorithm>

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


/**
 * 冒泡排序
 * 水中的气泡，大的泡泡会先冒上来，因为浮力比较大
 * 数据排序的话，从头到尾依次比较相邻元素大小，把大的元素放到后面，无序区间的最大值会不断上浮。 
 * 经过 n + (n-1) + ... + 1 = n(n+1)/2 = n2 次比较后，排序完毕
 */ 
void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) // 第几轮
    {
        // 每一轮过后，有序区间的元素数量都增加1
        // 下面是每一轮具体的元素比较交换处理   
        for (int j = 0; j < size - 1 - i; j++) 
        {
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[] = { 4, 4, 6, 5, 3, 2, 8, 1, 7, 5, 6, 0, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    print_arr(arr, size);
    bubble_sort(arr, size);
    std::cout << "bubble sort后元素输出：" << std::endl;
    print_arr(arr, size);

    return 0;
}
