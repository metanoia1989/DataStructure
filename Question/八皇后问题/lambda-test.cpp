#include <iostream>


/**
 * 主要测试lambda的值捕获，当值改变后，其捕获的值是否随之改变
 * 
 */ 
int main(int argc, char const *argv[])
{
    int value = 100;
    auto testChange = [value]() {
        std::cout << "[lambda] 当前的值为：" << value << std::endl;
    };

    value = 1000;  
    std::cout << "[main] 当前的值为：" << value << std::endl;
    
    testChange();
    
    return 0;
}
