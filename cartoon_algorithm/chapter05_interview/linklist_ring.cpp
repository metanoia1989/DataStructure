#include <iostream>

//********************************************************************
// 判断链表是否有环
// 以下都是针对单环链表，单向链表只有可能有一个环  
// 利用数学追及问题的解法
// 设置两个指针p1和p2，
// 让p1以每次向后移动1个节点
// 让p2以每次向后移动2个节点
// 当两个指针到达末尾时，有重合时则是有环，没有重合时则是没有环
//********************************************************************

// 链表节点
struct Node
{
    int data;
    Node *next;

    Node(int data) {
        this->data = data;    
    }
};

/**
 * 判断链表是否有环
 *
 * @param  {Node*} head : 
 * @return {bool}       : 
 */
bool isCycle(Node *head)
{
    Node *p1 = head;
    Node *p2 = head;
    
    while (p2 != nullptr && p2->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) {
            return true;
        }
    }
    return false;
}

/**
 * 计算有环链表的环长
 *
 * @param  {Node*} head : 
 * @return {int}        : 
 */
int cycleLength(Node *head)
{
    Node *p1 = head;
    Node *p2 = head;
    int length = 0;
    
    while (p2 != nullptr && p2->next != nullptr) {
        p1 = p1->next;
        p2 = p2->next->next;
        length++;
        if (p1 == p2) {
            return length;
        }
    }
    return length;
}

/**
 * 获取链表环的起始点
 *
 * @param  {Node*} head : 
 * @return {int}        : 
 */
int circleStart(Node *head)
{
     
}

int main(int argc, char const *argv[])
{
    Node *node1 = new Node(5);
    Node *node2 = new Node(3);
    Node *node3 = new Node(7);
    Node *node4 = new Node(2);
    Node *node5 = new Node(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node2;
    
    std::cout << "此链表是否有环：" << isCycle(node1) << std::endl; 
    std::cout << "此链表的环长为：" << cycleLength(node1) << std::endl; 

    return 0;
}

