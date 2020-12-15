#include <cstdlib>
#include <stdexcept>
#include <iostream>

template <typename T>
class array
{
public:
    array() = delete;

    array(int size = 10) 
    {
        m_count = 0;
        m_size = size;
        m_arr = new T[m_size];
    }

    ~array() 
    {
        delete[] m_arr;
    }

    /**
     * 随机访问元素
     * @param  {int} index  
     * @return {T}          
     */
    T operator[](int index) {
        return m_arr[index];     
    }

    /**
     * 更新元素
     * @param  {int} index  
     * @param  {T} value    
     */
    void update(int index, T element)
    {
        m_arr[index] = element; 
    }
    
    /**
     * 插入新元素
     * 数组元素插入的三种情况：
     * 1. 尾部插入，直接把元素放在数组尾部的空闲位置即可
     * 2. 中间插入
     * 3. 超范围插入
     * @param  {int} index    
     * @param  {int} element  
     */
    void insert(int index, T element)
    {
        // =_= 下面的代码是苗条代码 
        if (index == m_count && index < m_size) { // 尾部插入
            m_arr[m_count] = element;
        } else if ( index < 0 || index > m_size) { 
            throw std::overflow_error("illegal subscript！" + std::to_string(__LINE__));
        } else if (index < m_count) { // 中间插入
            // 从右到左循环，将元素逐个向右挪一位
            for (int i = m_count - 1; i >= index; i--)
            {
                m_arr[i+1] = m_arr[i];
            }
            m_arr[index] = element;
        } else if (index == m_size ) {
            resize(); // 数组扩容 
            m_arr[index] = element;
        } else {
            throw std::overflow_error("illegal subscript！" + std::to_string(__LINE__));
        }
        m_count++;
    }
    
    /** 
     * 数组扩容，创建两倍大小于现数组大小的新数组
     */ 
    void resize()
    {
        T *new_arr = new T[m_size * 2];
        for (int i = 0; i < m_size; i++)
        {
            new_arr[i] = std::move(m_arr[i]);
        }
        m_arr = new_arr; 
        new_arr = nullptr;
        m_size = m_size * 2;
    }
    
    T erase(int index)
    {
        if (index < 0 || index >= m_size) {
            throw std::overflow_error("illegal subscript！" + std::to_string(__LINE__));
        }     
        T element = m_arr[index];
        // 移动数组后续元素
        for (size_t i = index; i < m_size  - 1; i++)
        {
            m_arr[i] = m_arr[i+1];
        }
        m_count--;
        return element;
    }
    
    void printArray()
    {
        std::cout << "output array element：" << std::endl;    
        for (int i = 0; i < m_count; i++)
        {
            std::cout << m_arr[i] << ", ";
        }
        std::cout << std::endl;
        std::cout << "current array size：" << m_size << std::endl;
        std::cout << "current array count：" << m_count << std::endl;
    }

private:
    T *m_arr;
    int m_size;
    int m_count;
};



int main(int argc, char const *argv[])
{
    try {
        std::cout << "test output！" << std::endl;
        auto arr = new array<int>(5);
        arr->insert(0, 3);
        arr->insert(1, 7);
        arr->insert(2, 9);
        arr->insert(3, 5);
        arr->insert(4, 6);
        arr->insert(5, 8);
        arr->printArray();
        
        arr->erase(4);
        arr->printArray();
    } catch (const std::exception&e) {
        std::cout << "error: " << e.what() << std::endl;    
    }
    return 0;
}
