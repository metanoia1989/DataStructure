#!/usr/bin/env python3
#-*- coding: utf-8 -*-


# Python 实现的 B-Tree 
# 教程地址 https://www.programiz.com/dsa/b-tree 
# 光抄代码没有用，要真正弄懂，然后自己闭卷来实现出来，并且看看有没有值得优化的点    

"""
B-Tree Properties
1. For each node x, the keys are stored in increasing order.
2. In each node, there is a boolean value x.leaf which is true if x is a leaf.
3. If n is the order of the tree, each internal node can contain at most n - 1 keys along with a pointer to each child.
4. Each node except root can have at most n children and at least n/2 children.
5. All leaves have the same depth (i.e. height-h of the tree).
6. The root has at least 2 children and contains a minimum of 1 key.
7. If n ≥ 1, then for any n-key B-tree of height h and minimum degree t ≥ 2, h ≥ logt (n+1)/2.


Searching Operation
Searching for an element in a B-tree is the generalized form of searching an element in a Binary Search Tree. 
The following steps are followed.

1. Starting from the root node, compare k with the first key of the node.  
If k = the first key of the node, return the node and the index.
2. If k.leaf = true, return NULL (i.e. not found).
3. If k < the first key of the root node, search the left child of this key recursively.
4. If there is more than one key in the current node and k > the first key, compare k with the next key in the node.
If k < next key, search the left child of this key (ie. k lies in between the first and the second keys).
Else, search the right child of the key.
5. Repeat steps 1 to 4 until the leaf is reached.

Insertion Operation
1. If the tree is empty, allocate a root node and insert the key.
2. Update the allowed number of keys in the node.
3. Search the appropriate node for insertion.
4. If the node is full, follow the steps below.
5. Insert the elements in increasing order.
6. Now, there are elements greater than its limit. So, split at the median.
7. Push the median key upwards and make the left keys as a left child and the right keys as a right child.
8. If the node is not full, follow the steps below.
9. Insert the node in increasing order.


"""

class BTreeNode:
    """
    BTree 节点
    """
    def __init__(self, leaf = False) -> None:
        self.leaf = leaf
        self.keys = []
        self.child = []
        

class BTree:
    """
    BTree类
    """
    def __init__(self, t) -> None:
        self.root = BTreeNode(True) 
        self.t = t
        
    def print_tree(self, x, l = 0):
        """ 
        打印树
        """ 
        print("Level ", l, " ", len(x.keys), end = ":")
        for i in x.keys:
            print(i, end = " ")
        print()
        l += 1
        if len(x.child) > 0:
            for i in x.child:
                self.print_tree(i, l)
                
    def search_key(self, k, x=None):
        """ 
        搜索键
        """ 
        if x is not None:
            # 从某一个节点开始搜索  
            i = 0
            while i < len(x.keys) and k > x.keys[i][0]:
                i += 1
            if i < len(x.keys) and k == x.keys[i][0]:
                # 当前节点找到了键
                return (x, i)
            elif x.leaf:
                # 到达了叶子节点
                return None
            else:
                # 搜索子节点
                return self.search_key(k, x.child[i])
        else:
            # 从根节点开始搜索
            return self.search_key(k, self.root)
        
    def insert(self, k):
        """ 
        插入一个键，哈哈，我想起来了，我第一次抄这个的时候，这个代码是有问题的
        看来得自己弄清楚，才能改善地能正常地使用    
        而且这个也不太合理，总是从根节点开始插入    
        """ 
        root = self.root
        if len(root.keys) == (2 * self.t) - 1:
            temp = BTreeNode()
            self.root = temp
            temp.child.insert(0, root)
            self.split_child(temp, 0)
            self.insert_non_full(temp, k)
        else:
            self.insert_non_full(root, k)
            
    def insert_non_full(self, x, k):
        i = len(x.keys) - 1
        if x.leaf:
            x.keys.append((None, None))
            while i >= 0 and k[0] < x.keys[i][0]:
                x.keys[i+1] = x.keys[i]
                i -= 1
            x.keys[i+1] = k
        else:
            while i >= 0 and k[0] < x.keys[i][0]:
                i -= 1
            i += 1
            if len(x.child[i].keys) == (2 * self.t) - 1:
                self.split_child(x, i)
                if k[0] < x.keys[i][0]:
                    i += 1
            self.insert_non_full(x.child[i], k)
            
    def split_child(self, x, i):
        t = self.t
        y = x.child[i]
        z = BTreeNode(y.leaf)
        x.child.insert(i + 1, z)
        x.keys.insert(i, y.keys[t - 1])
        z.keys = y.keys[t: (2 * t) - 1]
        y.keys = y.keys[0: t - 1]
        if not y.leaf:
            z.child = y.child[t: 2 * t]
            y.child = y.child[0: t - 1]

            
if __name__ == '__main__':
    B = BTree(3)
    
    for i in range(10):
        B.insert((i, 2*i))
        
    B.print_tree(B.root)
    
    if B.search_key(8) is not None:
        print("\nFound")
    else:
        print("\nNot Found")
        