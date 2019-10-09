//
// Created by Administrator on 2019/9/26.
//

int main()
{
    /* 静态声明数组大小 */
    // 指针是固定的，a 是一个常量
    int a[5], *p;
    // 数组元素相加
    for (int i = 1, sum = a[0]; i < 5; ++i) {
        sum += a[i];
    }
    // 数组符号可以用指针替代
    for (int i = 0, sum = *a; i < 5; ++i) {
        sum += *(a+i);
    }
    for (sum = *a, p = a+1; p < a+5; p++) {
        sum += *p;
    }

    /* 动态声明数组大小 */
    int n = 5;
    p = new int[n];
    for (sum = p[0], i = 1; i < n; i++) {
        sum += p[i];
    }
    for (sum=*p, i=1; i<n; i++) {
        sum += *(p+1);
    }
    for (sum=*p,q=p+1; q<p+n; q++) {
        sum += *q;
    }
    delete [] p;

    return 0;
}
