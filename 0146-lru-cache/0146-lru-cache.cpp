struct DoublyLinkedList{
    int val;
    int key;


    DoublyLinkedList * prev;
    DoublyLinkedList * next;

    DoublyLinkedList(int x, int y) : key(x), val(y), prev(NULL), next(NULL) {}

};

class LRUCache {

private:

    unordered_map<int,DoublyLinkedList*> cache;

    struct DoublyLinkedList * lruWatcha= new DoublyLinkedList(0,0);
    struct DoublyLinkedList * mruWatcha = new DoublyLinkedList(0,0);
    
    int cap;

public:

    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        lruWatcha->next = mruWatcha;
        mruWatcha->prev = lruWatcha;
    }
    
    void remove(struct DoublyLinkedList* node){
        struct DoublyLinkedList * prev = node->prev;
        struct DoublyLinkedList * next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void add(struct DoublyLinkedList * node){
        struct DoublyLinkedList * mru = mruWatcha->prev;
        mru->next = node;
        node->prev = mru;
        node->next = mruWatcha;
        mruWatcha->prev = node;
    }

    int get(int key) {
        if(cache.find(key) != cache.end()){
            struct DoublyLinkedList* tmp = cache[key];
            remove(tmp);
            add(tmp);
            return tmp->val; 
        }
        
        return -1;
        
    }
    
    void put(int key, int value) {
        struct DoublyLinkedList* tmp;
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        
        tmp = new DoublyLinkedList(key,value);
        cache[key] = tmp;
        add(tmp);
        if (cache.size() > cap){
            struct DoublyLinkedList * lru = lruWatcha->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */