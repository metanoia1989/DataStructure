#include <iostream>
#include <stack>

//***********************************************************************
// 用栈来实现队列   
// 用两个栈来实现，栈A用来做入队操作，每次入队操作的元素，都压入栈A
// 当需要进行出队操作时，检测栈B是否为空，为空则将栈A的所有元素移动到栈B
// 这样栈B出栈元素序列刚好是栈A的入栈顺序
//***********************************************************************

class StackQueue
{
public:    
    /**
     * 入队操作
     * @param  {int} element : 入队元素
     */
    void enQueue(int element)
    {
        stackA.push(element); 
    }
    
    /**
     * 出队操作
     *
     * @return {int}  : 
     */
    int deQueue()
    {
        if (stackB.empty()) {
            if (stackA.empty()) {
                throw "队列为空，出队操作失败！";
            }
            transfer();
        } 
        int element = stackB.top();
        stackB.pop();
        return element;
    }
    
private:
    /**
     * 栈A元素转移到栈B
     */ 
    void transfer()
    {
        while (!stackA.empty()) {
            int element = stackA.top();
            stackA.pop();
            stackB.push(element);
        }
    }

private:
    std::stack<int> stackA;
    std::stack<int> stackB;
};

int main(int argc, char const *argv[])
{
    StackQueue queue;   
    queue.enQueue(1);
    queue.enQueue(2);
    queue.enQueue(3);
    
    std::cout << "队列出队操作，出队元素为：" << queue.deQueue() << std::endl;
    std::cout << "队列出队操作，出队元素为：" << queue.deQueue() << std::endl;

    queue.enQueue(4);

    std::cout << "队列出队操作，出队元素为：" << queue.deQueue() << std::endl;
    std::cout << "队列出队操作，出队元素为：" << queue.deQueue() << std::endl;

    return 0;
}
