#include <cstdlib>
#include <exception>

template <typename T>
class array
{
public:
    array() = delete;

    array(int count = 10) 
    {
        m_size = count;
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
     * @param  {int} index    
     * @param  {int} element  
     */
    void insert(int index, int element)
    {
        
    }
    
    /** 
     * 数组扩容
     */ 
    void resize()
    {
        
    }
    
    T delete(int index)
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
        return element;
    }

private:
    T *m_arr;
    int m_size;
};
