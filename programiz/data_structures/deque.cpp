#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

/**
 * deque 双端队列，队列收尾都可以进行入列出列操作
 * 接口如下：
 * insertFront() 向deque头部添加元素
 * insertLast() 向deque尾部添加元素
 * deleteFront() 删除deque头部的元素
 * deleteLast() 删除deque尾部的元素
 * getFront() 获取deque头部的元素
 * getRear() 获取deque尾部的元素
 * isEmpty() 检测deque是否为空
 * isFull() 检测deque是否为已满
 */ 

/** 
 * deque异常类
 */ 
class DequeException : std::exception {
public:
    explicit DequeException(const std::string& message) 
        : m_message(message) {};
    virtual const char* what() const throw() {
        return m_message.c_str();
    }
private:
    std::string m_message;
};

template<typename T>
class Deque;

template<typename T>
void printDeque(Deque<T>& deque);

template<typename T>
class Deque
{
public:    
    Deque(int size = 10); 
    ~Deque(); 
    void insertFront(T key);
    void insertLast(T key);
    void deleteFront();
    void deleteLast();
    T getFront();
    T getRear();
    bool isEmpty();
    bool isFull();

private:
    T *items;
    int front;
    int rear;
    int capacity;
    int count;
    
    friend void printDeque<T>(Deque<T>& deque);
};

template<typename T>
Deque<T>::Deque(int size)
{
    items = new T[size];
    front = -1;
    rear = -1;
    capacity = size;
    count = 0;
}

template<typename T>
Deque<T>::~Deque()
{
    delete[] items;
    items = nullptr;
}

template<typename T>
void Deque<T>::insertFront(T key)
{
    if (isFull()) {
        throw DequeException("overflow, deque已满，无法再插入元素");
    }
    // deque为空，front为0，front大于0
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = capacity - 1;
    } else {
        front--;
    }
    items[front] = key;
    count++;
    std::cout << "count: " << count << std::endl;
}

template<typename T>
void Deque<T>::insertLast(T key)
{
    if (isFull()) {
        throw DequeException("overflow, deque已满，无法再插入元素");
    }
    if (rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }
    items[rear] = key;
    count++;
}

template<typename T>
void Deque<T>::deleteFront()
{
    if (isEmpty()) {
        throw DequeException("deque已空，无法再删除元素");
    }
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    count--;
}

template<typename T>
void Deque<T>::deleteLast()
{
    if (isEmpty()) {
        throw DequeException("deque已空，无法再删除元素");
    }
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = capacity - 1;
    } else {
        rear = rear - 1;
    }
    count--;
}

template <typename T>
T Deque<T>::getFront()
{
    if (isEmpty()) {
        throw DequeException("underflow");
    }
    return items[front];
}

template <typename T>
T Deque<T>::getRear()
{
    if (isEmpty()) {
        throw DequeException("underflow");
    }
    return items[rear];
}

template <typename T>
bool Deque<T>::isEmpty()
{
    // 可以利用首尾指针来检测 front == -1 || rear == -1
    return count == 0;
}

template <typename T>
bool Deque<T>::isFull()
{
    // 利用首尾指针检测 
    // 1. front == 0 && rear == capacity - 1
    // 2. front == rear + 1
    return capacity == count;
}

template <typename T>
void printDeque(Deque<T>& deque)
{
    if (deque.isEmpty()) {
        std::cout << "双端队列为空！" << std::endl;
        return;
    }
    int cur = deque.front;
    std::cout << "队列元素为：";
    std::cout << deque.items[cur] << ", ";
    while (cur != deque.rear) {
        cur = (cur + 1 ) % deque.capacity;
        std::cout << deque.items[cur] << ", ";
    }
    std::cout << std::endl;
}


TEST_CASE("测试deque双端队列的接口") {
    auto deque = Deque<int>(4);

    std::cout << "插入元素到双端队列队列头部：5, 10" << std::endl;
    deque.insertLast(5);
    deque.insertLast(10);
    printDeque(deque);
    CHECK(deque.getRear() == 10);

    deque.deleteLast();
    printDeque(deque);
    CHECK(deque.getRear() == 5);

    std::cout << "插入元素到双端队列队列头部：15" << std::endl;
    deque.insertFront(15);
    printDeque(deque);
    CHECK(deque.getFront() == 15);

    std::cout << "删除双端队列对头元素" << std::endl;
    deque.deleteFront();
    printDeque(deque);
    CHECK(deque.getRear() == 5);


    std::cout << "删除双端队列剩下的元素，检测是否为空" << std::endl;
    deque.deleteFront();
    printDeque(deque);
    CHECK(deque.isEmpty());
    CHECK_THROWS_AS(deque.deleteFront(), DequeException);

    std::cout << "填满双端队列，检测是否抛出异常" << std::endl;
    deque.insertFront(2);
    deque.insertFront(1);
    deque.insertLast(3);
    deque.insertLast(4);
    printDeque(deque);
    CHECK(deque.isFull());
    CHECK_THROWS_AS(deque.insertLast(1), DequeException);
}