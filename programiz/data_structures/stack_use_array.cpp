#include <iostream>
#include <exception>

/** 
 * 栈数据结构，使用数组实现
 * 入栈、出栈时间复杂度为1  
 * 用途：
 * 1. 反转一个单词，先将单词所有的字母入栈，然后出栈即可实现反转。
 * 2. 编译器使用堆栈通过将表达式转换为前缀或后缀形式来计算表达式值。    
 * 3. 浏览器历史记录，每查看一个页面入栈，返回上一页出栈。  
 */ 

class StackFullPushException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "栈已满，无法插入元素";
    }
} stack_full_exception;

class StackEmptyPopException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "栈已空，无法弹出元素";
    }
} stack_empty_exception;

class StackEmptyPeekException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "栈已空，无法获取最上面的元素";
    }
} stack_empty_peek_exception;

struct Stack {
    Stack(int size = 10) : m_top(-1), m_size(size) 
    {
        arr = new int[m_size];
    }
    ~Stack() 
    {
        delete[] arr;
        arr = nullptr;
    }

    bool isFull() 
    {
        return m_top == m_size - 1;
    }

    bool isEmpty() 
    {
        return m_top == -1;
    }

    void push(int newItem) 
    {
        if (isFull()) {
            throw stack_full_exception;
        }
        arr[++m_top] = newItem;
    }

    int pop() 
    {
        if (isEmpty()) {
            throw stack_empty_exception;
        }
        return arr[m_top--];
    }

    int peek()
    {
        if (isEmpty()) {
            throw stack_empty_peek_exception;
        }
        return arr[m_top];
    }

    int size()
    {
        return m_top + 1;
    }

    void print()
    {
        for (int i = 0; i <= m_top; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int m_size = 10;
    int* arr;
    int m_top;
};

int main(int argc, char const *argv[])
{
    Stack my_stack = Stack(10);
    my_stack.push(1);
    my_stack.push(5);
    my_stack.push(9);
    my_stack.push(2);
    my_stack.print();

    my_stack.pop();
    my_stack.print();

    return 0;
}
