#!/usr/bin/env python3
#-*- coding: utf-8 -*-

class Node:
    def __init__(self, t):
        self.t = t
        self.keys = []
        self.children = []
        
    @property
    def is_leaf(self):
        return len(self.children) == 0
    
    @property
    def is_full(self):
        return len(self.keys) >= 2 * self.t - 1

    def split_child(self, i):
        new_node = self.__class__(self.t)
        split_node = self.children[i] 
        self.keys.insert(i, split_node.keys[self.t-1])
        self.children.insert(i+1, new_node)
        new_node.keys = split_node.keys[self.t:]
        split_node.keys = split_node.keys[:self.t-1]
        if not split_node.is_leaf:
            new_node.children = split_node.children[self.t:]
            split_node.children = split_node.children[:self.t]
    
class Btree:
    def __init__(self, t):

        self.t = t
        if self.t <= 1:
            raise ValueError("B-Tree must have a degree of 2 or more.")
        
        self.root = Node(t)
        
        
    def insert(self, key):
        if self.root.is_full:
            new_node = self.__class__(self.t)
            new_node.children.insert(0, self.root)
            new_node.split(0)
            self.root = new_node
        return self.insert_nonfull(key)
    
    # def insert_nonfull(self, key):
    #     if 
            