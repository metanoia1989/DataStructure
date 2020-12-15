#include <iostream>
#include <stack>

//************************************************************
// 最小栈，让栈的出栈、入栈、取最小元素的时间复杂度都为O(1)
// 设置两个栈，栈A用来正常左入栈出栈操作，栈B用来存储最小值
// 第一个元素入栈A时，也同时入栈B，之后每次新元素入栈A时，
// 都比较栈B的栈顶元素，如果小于或等于其栈顶元素，则新元素进入栈B
// 每当栈A有元素出栈，如果出栈元素等于栈B栈顶元素，则栈B进行出栈操作
//************************************************************


class MinStack
{
public:
    /**
     * 入栈操作
     * @param  {int} element : 
     */
    void push(int element)
    {
        m_main_stack.push(element);    
        // 辅助栈为空，或者新元素小于等于辅助栈栈顶元素
        if (m_min_stack.empty() || element <= m_min_stack.top()) {
            m_min_stack.push(element);
        }
    }

    /**
     * 出栈操作
     */
    void pop()
    {
        // 如果出栈元素和辅助栈栈顶元素值相等，辅助栈出栈
        if (m_main_stack.top() == m_min_stack.top()) {
            m_min_stack.pop();
        }
        m_main_stack.pop();
    }
    
    /**
     * 获取栈的最小值
     * @return {int}  : 
     */
    int getMin()
    {
        if (m_main_stack.empty()) {
            throw "stack is empty";
        } 
        return m_min_stack.top();
    }

private:
    std::stack<int> m_main_stack;
    std::stack<int> m_min_stack;
};

int main(int argc, char const *argv[])
{
    MinStack stack; 
    stack.push(4);
    stack.push(9);
    stack.push(7);
    stack.push(3);
    stack.push(8);
    stack.push(5);
    std::cout << "栈的最小值为：" << stack.getMin() << std::endl;
    stack.pop();
    stack.pop();
    stack.pop();
    std::cout << "栈的最小值为：" << stack.getMin() << std::endl;

    return 0;
}
