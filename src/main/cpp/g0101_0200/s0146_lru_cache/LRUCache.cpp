// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #Hash_Table #Design #Linked_List
// #Doubly_Linked_List #Udemy_Linked_List #Big_O_Time_O(1)_Space_O(capacity)
// #2024_05_27_Time_315_ms_(91.40%)_Space_168.7_MB_(78.28%)

#include <unordered_map>

class LRUCache {
private:
    struct LruCacheNode {
        int key;
        int value;
        LruCacheNode* prev;
        LruCacheNode* next;

        LruCacheNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, LruCacheNode*> cacheMap;
    LruCacheNode* head;
    LruCacheNode* tail;

public:
    LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}

    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            return -1;
        }
        LruCacheNode* val = it->second;
        moveToHead(val);
        return val->value;
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            LruCacheNode* valNode = it->second;
            valNode->value = value;
            moveToHead(valNode);
        } else {
            if (cacheMap.size() < capacity) {
                LruCacheNode* node = new LruCacheNode(key, value);
                cacheMap[key] = node;
                if (head == nullptr) {
                    head = node;
                    tail = node;
                } else {
                    node->next = head;
                    head->prev = node;
                    head = node;
                }
            } else {
                // Remove from tail
                LruCacheNode* last = tail;
                tail = last->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
                cacheMap.erase(last->key);
                delete last;
                if (cacheMap.size() == 0) {
                    head = nullptr;
                }
                // Call recursively
                put(key, value);
            }
        }
    }

private:
    void moveToHead(LruCacheNode* node) {
        if (node == head) {
            return;
        }
        if (node == tail) {
            tail = node->prev;
        }
        LruCacheNode* prev = node->prev;
        LruCacheNode* next = node->next;
        prev->next = next;
        if (next != nullptr) {
            next->prev = prev;
        }
        node->prev = nullptr;
        node->next = head;
        head->prev = node;
        head = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
