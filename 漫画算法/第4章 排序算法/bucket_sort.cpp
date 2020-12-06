#include <iostream>
#include <cmath>
#include <list>
#include <vector>
#include <algorithm>


// 桶排序算法伪代码说明 
// bucketSort()
//   create N buckets each of which can hold a range of values
//   for all the buckets
//     initialize each bucket with 0 values
//   for all the buckets
//     put elements into buckets matching the range
//   for all the buckets 
//     sort elements in each bucket
//   gather elements from each bucket
// end bucketSort

double *bucketSort(double arr[], const size_t size)
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
    
    // 2. 初始化桶
    const size_t bucketNum = size;
    std::vector<double> buckets[bucketNum];
    double section = (max - min) / bucketNum; // 桶的区间
    
    // 3. 遍历原始数组，将每个元素放入桶中
    for (int i = 0; i < bucketNum; i++) {
        // 如何确定桶的索引     
        // 桶的区间 = (max - min) / bucketNum
        // 桶的索引 = (value - min) / 桶的区间 and 向下取整
        int num = ceil((arr[i] - min) / section) - 1;
        if (num < 0) num = 0;
        buckets[num].push_back(arr[i]);
        // std::cout << bucketNum << "测试，桶的索引为：" << num << "->" << arr[i] << std::endl; 
    }
    
    // 4.堆每个桶内部进行排序
    for (int i = 0; i < bucketNum; i++) {
        std::sort(buckets[i].begin(), buckets[i].end()); 
    }
    
    // 5. 合并所有的桶
    double *sortedArr = new double[size];
    int index = 0;
    int count = 0;
    for (int i=0; i<bucketNum; i++) {
        count += buckets[i].size();
        for (int j=0; j<buckets[i].size(); j++) {
            sortedArr[index]  = buckets[i].at(j);
            index++;
        }
        
    }
    return sortedArr;
}

template <typename T>
void printArray(T arr[], int size)
{
    std::cout << "数组元素为：";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << ",";
    }
    std::cout << std::endl;
}



int main(int argc, char const *argv[])
{
    double arr[] = {
        4.12, 6.421, 0.0023, 3.0, 2.123,
        8.122, 4.12, 10.09
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    printArray(arr, size);

    double *sorted_arr = bucketSort(arr, size);
    printArray(sorted_arr, size);

    return 0;
}
