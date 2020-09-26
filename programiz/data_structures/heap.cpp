#include <iostream>
#include <exception>
#include <algorithm>


/**
 * heap 堆
 * 二叉堆是特殊的完全二叉树，binary heap is a complete binary tree that satisfies the heap property.
 * 最大堆 max-heap：任何一个父节点的值，都大于或等于其左右子节点的值
 * 最小堆 min-heap：任意一个父节点的值，都小于或等于其左右子节点的值
 * heap 最关键的是heapify，构建heap、插入节点、删除节点，都要经过heapify。
 * 堆化的关键在于元素交换，从根节点向下，比较父节点与子节点的大小，不断地交换，让元素上浮。 
 */ 

/** 
 * 堆异常类
 */ 
class HeapException : std::exception {
public:
    explicit HeapException(const std::string& message) : m_message(message) {};
    virtual const char* what() const throw() {
        return m_message.c_str();
    }
private:
    std::string m_message;
};


/**
 * 二叉堆模板类
 */
template <typename T>
class Heap
{
public:
    /**
     * Heap 构造函数
     * 
     * @param  {int} capacity : 堆容量大小
     */
    Heap(int capacity = 10) {
        m_capacity = capacity;
        m_count = 0;
        m_arr = new T[m_capacity];  
    }

    /**
     * 从数组构建堆，从最后一个非叶子节点依次做下沉处理
     * 数组保存的是完全二叉树层序遍历的结果，找到最后一个非叶子节点的位置，
     * 并对每个非叶节点反向层次顺序执行堆化操作
     * 最后一个非叶子节点就是最后一个节点的父节点
     * Last non-leaf node = parent of last-node = ((n - 1) - 1) / 2
     * 
     * @param  {T*} arr : 
     * @param  int capacity : 堆大小
     * @return void
     */
    void createHeap(T *arr, int arr_size) {
        m_count = arr_size;

        // 拷贝数组
        for (int i=0; i<m_count; i++) {
            m_arr[i] = arr[i];
        }
        // 非子节点下沉操作
        int lastNonLeafIndex =  ((m_count - 1) - 1) / 2;
        for (int i=lastNonLeafIndex; i>=0; i--) {
            downAdjust(i);
        }
    }

    /**
     * 堆析构函数，清理资源
     */
    virtual ~Heap() {
        delete[] m_arr;
        m_arr = nullptr;
    }

    /**
     * 插入元素
     * 
     * @param  {T} key : 要插入的元素值
     */
    void insert(T key) {
        if (m_count == m_capacity) {
            throw HeapException("堆已满，无法再插入新元素");
        }
        // 将新元素插入到堆的末尾
        m_count++;
        int i = m_count - 1;
        m_arr[i] = key;

        // 对新元素进行上浮处理
        upAdjust(i);
    }

    /**
     * 删除根节点获取其值
     * @return {T}   
     */
    T extract() {
        if (m_count <= 0) {
            throw HeapException("堆已空，无法获取根节点值");
        }
        T root = m_arr[0];
        m_arr[0] = m_arr[m_count-1]; // 将最后一个节点值覆盖根节点值
        m_count--;
        // 根节点值被最后一个值覆盖，需要重新堆化，对根节点进行下沉操作
        downAdjust(0);
        return root;
    }

    int count() { return m_count; }
    int capacity() { return m_capacity; }
    bool isEmpty() { return m_count == 0; };
    void printArray() {
        for (int i = 0; i < m_count; i++) { 
            std::cout << m_arr[i] << ", ";
        }
    }

    // 堆元素迭代器
    class Iterator {
    public:
        Iterator(T *ptr) : ptr(ptr) {};
        Iterator operator++() {
            ++ptr;
            return *this;
        }
        bool operator!=(const Iterator &other) const {
            return ptr != other.ptr;
        }
        const T& operator*() const { return *ptr; }
    private:
        T* ptr;
    };

    Iterator begin() const { return Iterator(m_arr); }
    Iterator end() const { return Iterator(m_arr + m_count); }


protected:
    virtual void upAdjust(int index) = 0;
    virtual void downAdjust(int index) = 0;

    T *m_arr; // 数组容器指针
    int m_capacity; // 堆的容量
    int m_count; // 堆的元素大小
};



/**
 * 最小堆 min-heap
 * 何一个父节点的值，都小于或等于其左右子节点的值
 * 重写 upAdjust、downAdjust方法即可，维持最小堆的特性
 */
template<typename T>
class MinHeap : public Heap<T>
{
public:
    MinHeap(int capacity = 10) : Heap<T>(capacity) {};
    MinHeap(T *arr, int capacity = 10) : Heap<T>(arr, capacity) {};

protected:
    /**
     * 节点上浮，保证值小的节点上浮，插入节点时使用
     * 
     * @param  {int} index : 节点索引
     */
    void upAdjust(int index)
    {
        int childIndex = index;
        int parentIndex = (childIndex - 1) / 2;
        // 子节点小于父节点的值，则上浮，即交换父节点与子节点的值
        while (childIndex > 0 && m_arr[childIndex] < m_arr[parentIndex]) {
            std::swap(m_arr[childIndex], m_arr[parentIndex]); 
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    /**
     * 节点下沉，保证值大的节点下沉，删除节点时使用
     * 
     * @param  {int} index : 节点索引
     */
    void downAdjust(int index)
    {
        int smallest = index;

        // 比较父节点与左右子节点的大小，父节点不是最小值则进行交换，不断下沉迭代
        do {
            int leftChild = 2 * smallest + 1;
            int rightChild = 2 * smallest + 2;

            if (leftChild < m_count && m_arr[leftChild] < m_arr[smallest]) {
                smallest = leftChild; // 左节点值比父节点小
            }
            if (rightChild < m_count && m_arr[rightChild] < m_arr[smallest]) {
                smallest = rightChild; // 右节点比父节点值小
            }
            if (smallest != index) { // 当前节点值比左右节点大
                std::swap(m_arr[smallest], m_arr[index]);
                index = smallest;
            }
        } while (smallest != index);

    }

protected:
    using Heap<T>::m_arr;
    using Heap<T>::m_count;
    using Heap<T>::m_capacity; 
};

/**
 * 最小堆 max-heap
 * 何一个父节点的值，都大于或等于其左右子节点的值
 * 重写 upAdjust、downAdjust方法即可，维持最小堆的特性
 */
template<typename T>
class MaxHeap : public Heap<T>
{
public:
    MaxHeap(int capacity = 10) : Heap<T>(capacity) {};
    MaxHeap(T *arr, int capacity = 10) : Heap<T>(arr, capacity) {};

protected:
    /**
     * 节点上浮，保证值大的节点上浮，插入节点时使用
     * 
     * @param  {int} index : 节点索引
     */
    void upAdjust(int index)
    {
        int childIndex = index;
        int parentIndex = (childIndex - 1) / 2;
        // 子节点大于父节点的值，则上浮，即交换父节点与子节点的值
        while (childIndex > 0 && m_arr[childIndex] > m_arr[parentIndex]) {
            std::swap(m_arr[childIndex], m_arr[parentIndex]); 
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    /**
     * 节点下沉，保证值小的节点下沉，删除节点时使用
     * 
     * @param  {int} index : 节点索引
     */
    void downAdjust(int index)
    {
        int largest = index;

        // 比较父节点与左右子节点的大小，父节点不是最大值则进行交换，不断下沉迭代
        do {
            int leftChild = 2 * largest + 1;
            int rightChild = 2 * largest + 2;

            if (leftChild < m_count && m_arr[leftChild] > m_arr[largest]) {
                largest = leftChild; // 左节点值比父节点大
            }
            if (rightChild < m_count && m_arr[rightChild] > m_arr[largest]) {
                largest = rightChild; // 右节点比父节点值大
            }
            if (largest != index) { // 当前节点值比其左右左节点小
                std::swap(m_arr[largest], m_arr[index]);
                index = largest;
            }
        } while (largest != index);

    }

protected:
    using Heap<T>::m_arr;
    using Heap<T>::m_count;
    using Heap<T>::m_capacity; 
};


/**
 * 输出堆中的元素
 * @param  {Heap<T>} heap : 
 */
template<typename T>
void printHeap(T heap) 
{
    std::cout << "输出堆中的元素：";
    for (auto item : heap) {
        std::cout << item << ",";
    }
    std::cout << std::endl;
}

/**
 * 测试最大堆和最小堆
 */ 
int main(int argc, char const *argv[])
{
    // 构建最小堆 
    std::cout << "********* 最小堆构建测试 ************" << std::endl;
    int arr[] = { 10, 50, 15, 30, 40, 40, 100};
    auto minHeap = MinHeap<int>(10);
    minHeap.createHeap(arr, sizeof(arr) / sizeof(arr[0]));
    printHeap(minHeap);
    // 提取最小值
    auto min = minHeap.extract();
    std::cout << "获取堆中最小元素: " << min << std::endl;
    printHeap(minHeap);
    // 插入一个值
    minHeap.insert(1);
    printHeap(minHeap);

    // 构建最大堆 
    std::cout << "********* 最大堆构建测试 ************" << std::endl;
    int arr2[] = { 10, 50, 15, 30, 40, 40, 100};
    auto maxHeap = MaxHeap<int>(10);
    maxHeap.createHeap(arr2, sizeof(arr2) / sizeof(arr2[0]));
    printHeap(maxHeap);
    // 提取最大值
    auto max = maxHeap.extract();
    std::cout << "获取堆中最大元素: " << max << std::endl;
    printHeap(maxHeap);
    // 插入一个值
    maxHeap.insert(55);
    printHeap(maxHeap);
    return 0;
}
