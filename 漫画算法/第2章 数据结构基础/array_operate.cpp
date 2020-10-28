#include <cstdlib>
#include <exception>
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
    void insert(int index, int element)
    {
        if (index > m_count) { // 尾部插入
            m_arr[m_count] = element;
        } else if ( index < 0 || index > m_size) { // 中间插入
            throw new overflow_error("非法的数组下标！");
        }   
        if (index == m_size) {
            resize(); // 数组扩容 
        }
    }
    
    /** 
     * 数组扩容
     */ 
    void resize()
    {
        
    }
    
    T erase(int index)
    {
        if (index < 0 || index >= m_size) {
            throw new overflow_error("非法的数组下标！");
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

private:
    T *m_arr;
    int m_size;
    int m_count;
};

int main(int argc, char const *argv[])
{
    std::cout << "测试输出！" << std::endl;
    return 0;
}
