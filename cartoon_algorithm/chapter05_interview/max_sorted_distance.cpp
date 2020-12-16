#include <iostream>
#include <vector>

//*****************************************************************************
// 求无序数组排序后的最大相邻差
// 1. 利用桶排序的思想，根据原数组的长度n，创建出n个桶，每个桶代表一个区间范围。
// 第1个桶从原数组的最小值min开始，区间跨度是 (max-min)/(n-1)
// 2. 遍历原数组，把原数组每一个元素插入到对应的桶中，记录每一个桶的最大值和最小值
// 3. 遍历所有的桶，统计出每一个桶的最大值，和这个桶右侧非空桶的最小值的茶
// 数值最大的差即为原数组排序后的相邻最大差值
//*****************************************************************************
struct Bucket
{
    int min = 0;
    int max = 0;
};

int getMaxSortedDistance(int arr[], int size);

int main(int argc, char const *argv[])
{
    int arr[] = { 2, 6, 3, 4, 5, 10, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "此数组最大相邻差为：" << getMaxSortedDistance(arr, size) << std::endl;
    
    return 0;
}

/**
 * 求取无序数组排序后的最大相邻差
 */ 
int getMaxSortedDistance(int arr[], int size)
{
    int max = arr[0];
    int min = arr[0];
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    
    int d = max - min;
    // 如果 max 和 min 相等，说明数组所有元素都相等，返回0
    if (d == 0) {
        return 0;
    }
    
    // 初始化桶
    const size_t bucketNum = size;
    std::vector<Bucket*> buckets(bucketNum);
    for (size_t i = 0; i < bucketNum; i++)
    {
        buckets[i] = new Bucket();
    }


    // 遍历原始数组，确定每个桶的最大最小值
    for (size_t i = 0; i < bucketNum; i++)
    {
        // 确定数组元素所归属的桶下标
        int index = (arr[i] - min) * (bucketNum - 1) / d;
        auto bucket = buckets.at(index);
        if (bucket->min == 0 || bucket->min > arr[i]) {
            bucket->min = arr[i];
        }
        if (bucket->max == 0 || bucket->max < arr[i]) {
            bucket->max = arr[i];
        }
    }
    
    // 遍历桶，找到最大差值
    int leftMax = buckets.at(0)->max;
    int maxDistance = 0;
    for (size_t i = 1; i < bucketNum; i++)
    {
        if (buckets.at(i)->min == 0) {
            continue;
        }
        if (buckets.at(i)->min - leftMax > maxDistance) {
            maxDistance = buckets.at(i)->min - leftMax;
        }
        leftMax = buckets.at(i)->max;
    }
    return maxDistance;
}