//
// Created by Administrator on 2019/9/26.
//

/* 模板类 */
template<class genType>
class genClass
{
    genType storage[50];
};

genClass<int> intObject;
genClass<float> floatObject;

template<class genType, int size=50>
class genClass2
{
    genType storage[size];
};

genClass2<int> intObject2;  // 使用默认大小
genClass2<int, 100> intObject2;
genClass2<float, 123> floatObject;

/* 模板函数 */
template <class genType>
void swap(genType& el1, genType& el2)
{
    genType tmp = el1; el1 = el2; em2 = tmp;
}
