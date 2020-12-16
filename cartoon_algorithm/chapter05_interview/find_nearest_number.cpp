#include <iostream>
#include <algorithm>

//***********************************************************************
// 找到全排列的下一个数
// 在一个整数所包含数字的全部组合中，找到一个大于且大于原数的新整数
// 固定的几个数字，数字的顺序排列最小，逆序排列最大
// 要找到全排列的下一个数，尽量保持高位不变，低位在最小的范围内变换顺序
// 变换顺序的范围大小，则取决于当前整数的逆序区域   
// 如 12354 逆序区域为 54，从倒数第3位开始变，与逆序区域中大于3的最小数进行交换
// 得到数字 12453
// 
// 步骤说明如下：
// 1. 从后向前查看逆序区域，找到逆序区域的前一位，也就是数字置换的边界。
// 2. 让逆序区域的前一位和逆序区域中大于它的最小的数字交换位置
// 3. 把原来的逆序区域转为顺序状态  
// 
// 字典序算法   
//***********************************************************************
int* findNearestNumber(int numbers[], int size);
int findTransferPoint(int numbers[], int size);
int* exchangeHead(int numbers[], int size, int index);
int* reverse(int numbers[], int size, int index);
void printArr(int arr[], int size);

int main(int argc, char const *argv[])
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int *temp;
    std::copy(numbers, numbers + size, temp);
    // 打印12345之后的10个全排列整数
    for (int i=0; i<10; i++) {
        // findNearestNumber(temp, size);   
        temp = findNearestNumber(temp, size);   
        // break;
    }

    return 0;
}


int* findNearestNumber(int *numbers, int size)
{
    // 从后向前查看逆序区域，找到逆序区域的前一位，也就是数字置换的边界  
    int index = findTransferPoint(numbers, size);
    
    // 如果数字置换边界是0，说明整个数组已经逆序，无法得到更大的相同数字组成的整数，返回 null
    if (index == 0) {
        return nullptr;
    }

    // 把逆序区域的前一位和逆序区域中刚刚大于它的数字交换位置
    // 复制并入参，避免直接修改入参 
    int *numbersCopy;
    std::copy(numbers, numbers + size, numbersCopy);
    exchangeHead(numbersCopy, size, index);

    // 把原来的逆序区域转为顺序
    reverse(numbersCopy, size, index);
    return numbersCopy;
}

/**
 * 查看数组的逆序区域
 */ 
int findTransferPoint(int *numbers, int size)
{
    for (int i = size -1; i > 0; i--) {
        if (numbers[i] > numbers[i-1]) {
            return i;
        }
    } 
    return 0;
}

/**
 * 交换逆序区的前一位和逆序区域中刚刚大于它的数字
 */ 
int* exchangeHead(int *numbers, int size, int index)
{
    int head = numbers[index - 1];    
    for (int i = size - 1; i > 0; i--) {
        if (head < numbers[i])  {
            numbers[index-1] = numbers[i];
            numbers[i] = head;
            break;
        }
    }
    return numbers; 
}

/**
 * 把原先的逆序区转为顺序
 */ 
int* reverse(int *numbers, int size, int index)
{
    for (int i=index, j=size-1; i<j; i++,j--) {
        int temp = numbers[i]; 
        numbers[i] = numbers[j];
        numbers[j] = temp;
    } 
    return numbers;
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
