#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
栈的类实现
"""
class Stack(object):
    def __init__(self):
        self._stack = []

    def isEmpty(self):
        return len(self._stack) == 0

    def push(self, item):
        self._stack.append(item)
        print("pushed item: " + item)

    def pop(self):
        if (self.isEmpty()):
            return "stack is empty"
        return self._stack.pop()

    def __str__(self):
        return self._stack.__str__()


    
if __name__ == "__main__":
    stack = Stack()
    stack.push(str(1))
    stack.push(str(2))
    stack.push(str(3))
    stack.push(str(4))
    print("poped item: " + stack.pop())
    print("stack after poping an element: " + str(stack))
    