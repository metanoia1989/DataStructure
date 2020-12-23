#include <iostream>
#include <string>
#include <map>

//****************************************************************
// LRU Least Recently Used 最近最少使用的移除 的内存管理算法
// 使用哈希链表结构 最新的数据放到链表的最右侧
// 被访问到的数据也放到链表的最右侧
// 然后内存不够用的时候，从链表最左侧开始移除数据   
//****************************************************************


struct Node
{
    Node(std::string key, std::string value) {
        this->key = key; 
        this->value = value; 
    } 

    Node *prev;
    Node *next;
    std::string key;
    std::string value;
};

class LRUCache
{
public:    
    LRUCache(int limit) 
    {
        this->limit = limit; 
    }
    
    std::string get(std::string key)
    {
        auto hasExists = hashMap.find(key);
        if (hasExists == hashMap.end()) {
            return "";
        }
        Node *node = hashMap.at(key);
        refreshNode(node);
        return node->value;
    }
    
    void put(std::string key, std::string value)
    {
        auto hasExists = hashMap.find(key);
        if (hasExists == hashMap.end()) {
            // 如果key不存在，插入key-value
            if (hashMap.size() >= limit) {
                std::string oldKey = removeNode(head);
                hashMap.erase(oldKey);
            }
            auto node = new Node(key, value);
            addNode(node);
            hashMap.insert({key, node});
        } else {
            // 如果 key 存在，刷新key-value
            Node *node = hashMap.at(key); 
            node->value = value;
            refreshNode(node);
        }
    }
    
    void remove(std::string key)
    {
        Node *node = hashMap.at(key); 
        if (node == nullptr) {
            return;
        }
        removeNode(node);
        hashMap.erase(key);
    }
    
    /**
     * 刷新被访问的节点位置
     * @param  {Node*} node : 被访问的节点
     */
    void refreshNode(Node *node)
    {
        if (node == end) {
            return;
        } 
        // 移除节点
        removeNode(node);
        // 重新插入节点
        addNode(node);
    }

    /**
     * 删除节点
     *
     * @param  {Node*} node   : 
     * @return {std::string}  : 
     */
    std::string removeNode(Node *node)
    {
        if (node == head && node == end) {
            // 移除唯一的节点
            head = end = nullptr;
        } else if (node == end) {
            // 移除尾节点
            end = end->prev;
            end->next = nullptr;
        } else if (node == head) {
            // 移除头节点 
            head = head->next;
            head->prev = nullptr;
        } else {
            // 移除中间节点
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        return node->key;
    }
    
    /**
     * 尾部插入节点
     *
     * @param  {Node*} node : 
     */
    void addNode(Node *node)
    {
        if (end != nullptr) {
            end->next = node;
            node->prev = end;
            node->next = nullptr;
        } 
        end = node;
        if (head == nullptr) {
            head = node;
        }
    }

private:    
    Node *head;
    Node *end;
    int limit; // 缓存
    std::map<std::string, Node*> hashMap;
};


int main(int argc, char const *argv[])
{
    LRUCache lruCache = LRUCache(5);
    lruCache.put("001", "用户1信息");
    lruCache.put("002", "用户2信息");
    lruCache.put("003", "用户3信息");
    lruCache.put("004", "用户4信息");
    lruCache.put("005", "用户5信息");
    lruCache.get("002");
    lruCache.put("004", "用户4信息更新");
    lruCache.put("006", "用户6信息");
    std::cout << lruCache.get("001") << std::endl;
    std::cout << lruCache.get("006") << std::endl;
    std::cout << lruCache.get("004") << std::endl;

    return 0;
}
