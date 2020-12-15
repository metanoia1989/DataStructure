#include <iostream>
#include <stdexcept>

/**
 * 链表节点
 */ 
template <typename T>
struct Node
{
    T data;
    Node *next;
};

/**
 * 链表类
 */ 
template <typename T>
class Linklist
{
public:        
    Linklist()
    {
        head = tail = nullptr;    
        m_size = 0;
    }

    /**
     * 查找节点
     * 
     * @param  {T} data : 
     */
    Node<T> *find(int index)
    {
        if (index < 0 || index >= m_size) 
            throw std::overflow_error("超过链表节点范围");

        auto curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        return curr;
    }

    /**
     * 更新节点
     *
     * @param  {int} index: 
     * @param  {T} data : 
     */
    void update(int index, T data)
    {
        if (index < 0 || index >= m_size) 
            throw std::overflow_error("超过链表节点范围");

        auto curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;
        }
        curr->data = data;
    }

    /**
     * 插入节点
     *
     * 尾部插入：把最后一个节点的next指针指向新插入的节点       
     * 头部插入：把新节点的next指针指向原先的头节点，把新节点变为链表的头节点   
     * 中间插入：新节点的next指针指向插入位置的节点，插入位置前置节点的next指针指向新节点   
     *
     * @param  {T} data 
     * @param  {int} index
     */
    void insert(T data, int index)
    {
        std::cout << "插入元素：" << index << "->" << data << "，curr size：" << m_size << std::endl;

        if (index < 0 || index > m_size) 
            throw std::overflow_error("超过链表节点范围");

        auto new_node = new Node<T>();
        new_node->data = data;
        new_node->next = nullptr;

        if (m_size == 0) { // 空链表插入
            // 这样能链表首尾节点能够联通，不然的话无法形成链表
            head = tail = new_node;
        } else if (index == 0) { // 头部插入
            new_node->next = head;
            head = new_node;
        } else if (index == m_size) { // 尾部插入
            tail->next = new_node;
            tail = new_node;
        } else { // 中间插入
            auto curr = find(index - 1);
            auto prev = curr; // 要插入节点的前置节点
            curr = curr->next;
            prev->next = new_node;
            new_node->next = curr;
        }
        m_size++;
    }
    
    /**
     * 删除元素
     *
     * 尾部删除：把倒数第二个节点的next指针指向空即可   
     * 头部删除：把链表的头节点设为原先头节点的next指针即可  
     * 中间删除：把要删除节点的前置节点的next指针，指向要删除元素的下一个节点即可   
     *
     * @param  {int} index : 
     */
    Node<T>* erase(int index)
    {
        if (index < 0 || index > m_size) 
            throw std::overflow_error("超过链表节点范围");

        auto remove = new Node<T>();

        if (index == 0) { // 头部删除
            remove = head;
            head = head->next;
        } else if (index == m_size) { // 尾部删除
            auto curr = find(m_size - 1);
            curr->next = nullptr;
            remove = tail;
            tail = curr;
        } else { // 中间删除
            auto curr = find(index - 1); // 要删除节点的前置节点
            remove = curr->next;
            curr->next = curr->next->next;
        }
        return remove;
        
        m_size--;
    }
    
    /**
     * 输出链表数据
     */
    void print()
    {
        std::cout << "开始输出链表数据：";
        auto curr = head; 
        while (curr != nullptr) {
            std::cout << curr->data << ", ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

private:
    Node<T> *head; // 头节点指针 
    Node<T> *tail; // 尾节点指针 
    int m_size; // 链表实际长度 
};

int main(int argc, char const *argv[])
{
    std::cout << "输出测试！" << std::endl;

    try {
        auto linklist = new Linklist<int>();
        linklist->insert(3, 0);
        linklist->insert(7, 1);
        linklist->insert(9, 2);
        linklist->insert(5, 3);
        linklist->insert(6, 4);
        linklist->print();

        linklist->erase(3);
        linklist->print();
    } catch (const std::exception&e) {
        std::cout << "error: " << e.what() << std::endl;    
    }

    return 0;
}
