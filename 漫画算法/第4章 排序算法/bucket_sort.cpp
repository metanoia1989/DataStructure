#include <iostream>

void bucketSort(double arr[], int size)
{
    // 1. 得到数列的最大值和最小值，并算出差值d    
    double max = arr[0];
    double min = arr[0];
    for (int i=1; i<size; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    double d = max - min;
    
    // 2. 初始化桶
    int bucketNum = size;
    
}