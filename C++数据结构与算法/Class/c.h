//
// Created by Administrator on 2019/9/26.
//

#ifndef DATASTRUCTURE_C_H
#define DATASTRUCTURE_C_H

#include <iostream>

using  std::cout;

class C
{
public:
    C(char *s="", int i = 0, double d = 1)
    {
        strcpy(dataMember1, s);
        dataMember2 = i;
        dataMmeber3 = d;
    }

    void memberFunction1()
    {
        cout << dataMember1 << '' << dataMember2 << ''
            << dataMember3 << endl;
    }

    void memberFunction2(int i, char *s = "unknown")
    {
        dataMember2 = 1;
        cout << i << " received from " << s << endl;
    }

protected:
    char dataMember1[20];
    int dataMember2;
    double dataMember3;
};

C object1("object1", 100, 2000), object2("object2"), object3;

#endif //DATASTRUCTURE_C_H
