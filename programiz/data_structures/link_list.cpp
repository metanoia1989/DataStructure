#include <bits/stdc++.h>

class Node {
public:
    int value;
    Node* next;
};

int main(int argc, char const *argv[])
{
    Node* head;
    Node* one = nullptr;
    Node* two = nullptr;
    Node* three = nullptr;

    one = new Node();
    two = new Node();
    three = new Node();

    one->value = 1;
    two->value = 2;
    three->value = 3;

    one->next = two;
    two->next = three;
    three->next = nullptr;

    head = one;

    while (head != nullptr) {
        std::printf("%d", head->value);
        head = head->next;
    }

    return 0;
}
