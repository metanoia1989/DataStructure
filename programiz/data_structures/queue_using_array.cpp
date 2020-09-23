#include <iostream>
#include <exception>

/**
 * 队列，FIFO
 * 支持的接口：enqueue、dequeue、isEmpty、isFull、peek
 */ 
class QueueException : public std::exception
{
public:
    QueueException(std::string msg) : m_msg(msg) {}

    virtual const char* what() const throw()
    {
        return m_msg.c_str();
    }
private:
    std::string m_msg;
};  

auto queue_full_enqueue_exception = QueueException("队列已满，无法入列");
auto queue_empty_dequeue_exception = QueueException("队列已空，无法出队");
auto queue_empty_peek_exception = QueueException("队列已空，无法获取队首元素");

template <typename T>
class Queue {
public:
    Queue(int size = 10) {
        count = 0;
        capacity = size;
        items = new T[capacity];
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] items;
        items = nullptr;
    }

    bool isFull() {
        return count == capacity;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enqueue(T element) {
        if (isFull()) {
            throw queue_full_enqueue_exception;
        }
        rear = (rear + 1) % capacity; // 循环队列，充分利用数组空间
        items[rear] = element;
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw queue_empty_dequeue_exception;
        }
        T elment = items[front];
        front = (front + 1) % capacity;
        count--;
        return elment;
    }

    T peek() {
        if (isEmpty()) {
            throw queue_empty_peek_exception;
        }
        return items[front];
    }

    int size() {
        return count;
    }

    void display() {
        if (isEmpty()) {
            std::cout << "队列为空！" << std::endl;
            return;
        }
        int curr = front;
        std::cout << "队列元素为：";
        std::cout << items[curr];
        while (curr != rear) {
            curr = (curr + 1 ) % capacity;
            std::cout << items[curr];
        }
        std::cout << std::endl;
    }
private:
    T *items;
    int front;  // 队头指针
    int rear; // 队尾指针
    int capacity; // 队列容量
    int count; // 队列元素数量
};

int main(int argc, char const *argv[])
{
    Queue<std::string> queue(4);

    queue.enqueue("a");
    queue.enqueue("b");
    queue.enqueue("c");
    queue.enqueue("d");
    try {
        
        queue.enqueue("e");
    } catch (const std::exception& e) {
        std::cout << "入列失败: " << e.what() << std::endl;
    }
    queue.display();

    auto element = queue.dequeue();
    std::cout << "出队元素为：" << element << std::endl;

    queue.display();

    queue.enqueue("e");
    std::cout << "队列大小为：" << queue.size() << std::endl;
    queue.display();

    // 置空队列
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.display();

    return 0;
}
