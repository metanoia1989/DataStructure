#!/usr/bin/env python3
#-*- coding: utf-8 -*-

class BTreeNode:

    def __init__(self, keys = [], children = [], leaf = False) -> None:
        """
        B树节点

        keys(List): 存储的键
        children(List): 指向的其他节点
        leaf(Boolean): 是否是叶子节点
        """
        self.keys = []
        self.children = []
        self.leaf = leaf


class BTree:
    pass