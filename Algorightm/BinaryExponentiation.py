#!/usr/bin/env python3
#-*- coding: utf-8 -*-

'''
这个是求 m 的 n 次幂
'''
def binpow(m, n):
    if n == 0:
        return 1
    elif n % 2 == 0:
        return binpow(m, n / 2) * binpow(m, n / 2)
    else:
        return m * binpow(m, int(n / 2)) * binpow(m, int(n / 2))

'''
当 m 等于 n 的时候要怎么处理呢
'''

if __name__ == "__main__":
    print(binpow(2, 2))
    print(binpow(3, 3))
    print(binpow(4, 4))
