#!/usr/bin/env python3
#-*- coding: utf-8 -*-

"""
A simple B-Tree in Python that supports insert, search and print.
"""

class Node:
    """A simple B-Tree Node."""
    
    def __init__(self, t) -> None:
        self.t = t
        self.keys = []
        self.children = []
        self.leaf = True
        
    def split(self, parent, payload):
        """
        Split a node and reassign keys/children
        """
        new_node = self.__class__(self.t)
        
        mid_point = self.size // 2
        split_value = self.keys[mid_point]
        parent.add_key(split_value)
        
        # Add keys and children to appropriate nodes
        new_node.children = self.children[mid_point+1:]
        new_node.keys = self.keys[mid_point+1:]
        self.children = self.children[:mid_point+1]
        self.keys = self.keys[:mid_point]
        
        # If the new_node has children, set it as internal node
        if len(new_node.children) > 0:
            new_node.leaf = False
        
        parent.children = parent.add_child(new_node)
        if payload < split_value:
            return self
        else:
            return new_node
        
    def add_child(self, new_node):
        """
        添加一个孩子到节点，重新排序节点的孩子，排序之后中间分割

        returns: 有序的子节点列表
        """
        i = len(self.children) - 1
        while i >= 0 and self.children[i].keys[0] > new_node.keys[0]:
            i -= 1
        return self.children[:i+1] + [new_node] + self.children[i+i:]
    
    def add_key(self, value):
        """
        添加一个键到节点，节点根据定义要有放置键的空间
        """
        self.keys.append(value)
        self.keys.sort()
        
    @property
    def is_full(self):
        return self.size == 2 * self.t - 1
    
    @property
    def size(self):
        return len(self.keys)
        
    
class BTree:
    """
    具有搜索、插入功能的B树实现，任意度T都可以。    
    """
    
    def __init__(self, t):
        """
        创建B树。t是B树的度。树在创建时没有键。
        这个实现允许重复键的值，尽管还没有认真检查。
        """
        self.t = t
        if self.t <= 1:
            raise ValueError("B-Tree must have a degree of 2 or more.")
        
        self.root = Node(t)
        
        
    def insert(self, payload):
        """
        插入键的值负载到B树
        """
        node = self.root

        # 显式处理根节点，因为需要创建两个节点
        if node.is_full:
            new_root = Node(self.t)
            new_root.children.append(self.root)
            new_root.leaf = False
            node = node.split(new_root, payload)
            self.root = new_root
            
        while not node.leaf:
            i = node.size - 1
            while i > 0 and payload < node.keys[i]:
                i -= 1
            if payload > node.keys[i]:
                i += 1
                
            next = node.children[i]
            if next.is_full:
                node = next.split(node, payload)
            else:
                node = next
        # 从下的方法分割满的节点，我们能简单地插入负载到叶子节点
        node.add_key(payload)
        
    def search(self, value, node=None):
        """
        如果B树包含匹配值地键，返回True
        """
        if node is None:
            node = self.root

        if value in node.keys:
            return True
        elif node.leaf:
            return False
        else:
            i = 0
            while i < node.size and value > node.keys[i]:
                i += 1
            return self.search(value, node.children[i])
        
    def print_order(self):
        """
        打印层序排序的表示
        """
        this_levvel = [self.root]
        while this_levvel:
            next_level = []
            output = ""
            for node in this_levvel:
                if node.children:
                    next_level.extend(node.children)
                output += str(node.keys) + " "
            print(output)
            this_levvel = next_level
