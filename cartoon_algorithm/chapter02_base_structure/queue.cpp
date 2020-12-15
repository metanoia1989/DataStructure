#include <iostream>

class Queue
{
public:
    Queue(int capacity) 
    {
        this->capacity = capacity;
        arr = new int[capacity];
        rear = front = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    
    /**
     * 入列
     */ 
    void enqueue(int element)
    {
        if ((rear + 1) % capacity == front) {
            std::cout << "rear: " << rear << ", front: " << front << std::endl;
            throw "队列已满";
        }
        arr[rear] = element;
        rear = (rear + 1) % capacity;
    }
    
    /**
     * 出列
     */
    int dequeue()
    {
        if (rear == front) {
            throw "队列已空";
        }
        int element = arr[front];
        front = (front + 1) % capacity;
        return element;
    }
    
    /**
     * 输出队列
     */ 
    void output()
    {
        std::cout << "队列元素为：";
        for (int i=front; i!=rear; i=(i+1)%capacity)
        {
            std::cout << arr[i] << ",";   
        }
        std::cout << std::endl;
    }

private:
    int *arr;
    int capacity;
    int front;
    int rear;
};

int main(int argc, char const *argv[])
{
    Queue queue = Queue(6); 
    queue.enqueue(3);
    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(8);
    queue.enqueue(1);
    queue.output();
    
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.enqueue(2);
    queue.enqueue(4);
    queue.enqueue(9);
    queue.output();
    queue.enqueue(9);

    queue.output();

    return 0;
}
