//
// 指针与复制构造函数
//
#include <cstring>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

struct Node
{
    char *name;
    int age;
    Node(const char *n=" ", int a=0) {  // 默认构造函数
        name = strdup(n);
        age = a;
    }
    Node(const Node& n) {   // 拷贝构造函数
        name = strdup(n.name);
        age = n.age;
    }
    Node& operator=(const Node& n) { // 拷贝赋值运算符
        if (this!=&n) {
            if (name != nullptr) {
                free(name);
            }
            name = strdup(n.name);
            age = n.age;
        }
        return *this;
    }
    ~Node() {   // 
        if (name != nullptr) {
            free(name);
        }
    }
};


int main(int argc, char const *argv[])
{
    Node node1("Roger", 20), node2(node1);  
    cout << node1.name << " " << node1.age << " " << node2.name << " " << node2.age << endl;

    // 测试拷贝构造函数
    strcpy(node2.name, "Wendy");
    node2.age = 30;
    cout << node1.name << " " << node1.age << " " << node2.name << " " << node2.age << endl;

    // 测试拷贝赋值运算符
    node2 = node1;
    strcpy(node2.name, "Wendy");
    node2.age = 30;
    cout << node1.name << " " << node1.age << " " << node2.name << " " << node2.age << endl;

    return 0;
}
