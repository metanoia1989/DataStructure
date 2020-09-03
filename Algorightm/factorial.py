#!/usr/bin/env python3
#-*- coding: utf-8 -*-

'''
n 的 n 次方
'''

def aaa(n):
    if n <= 0:
        return 0

    p, q = n, n - 1

    while q > 0:
        p *= n
        q = q - 1

    return  p

if __name__ == "__main__":
    print("n = 2", aaa(2))
    print("n = 3", aaa(3))