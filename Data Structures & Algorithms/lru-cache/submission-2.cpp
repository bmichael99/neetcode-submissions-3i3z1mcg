class Node {
public:
  int key;
  int val;
  Node* next;
  Node* prev;

  Node(int key, int val){
    next = nullptr;
    prev = nullptr;
    this->key = key;
    this->val = val;
  }
};

class LRUCache {
public:
    int capacity;
    int size;
    unordered_map<int,Node*> cache; //key to node
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    int get(int key) {
        if(cache.contains(key)){
          useNode(cache[key]);
          return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.contains(key)){
          cache[key]->val = value;
          useNode(cache[key]);
        } else if(size == capacity){
          cache.erase(this->tail->key);
          removeNode(this->tail);
          this->size--;
        }
        
        if(!cache.contains(key)){
          cache[key] = new Node(key,value);
          insertHead(cache[key]);
          this->size++;
        }
    }

    void useNode(Node* curr){
      //most recently used nodes get placed at the head.
      removeNode(curr);
      insertHead(curr);
    }

    void insertHead(Node* curr){
      if(!this->head){
        this->head = curr;
        this->tail = curr;
      } else {
        curr->next = this->head;
        this->head->prev = curr;
        this->head = curr;
      }
    }

    void removeNode(Node* curr){
      if(curr == head && curr == tail){
        this->head = nullptr;
        this->tail = nullptr;
      } else if(curr == head){
        this->head = this->head->next;
        this->head->prev = nullptr;
      } else if(curr == tail){
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
      } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
      }
      curr->next = nullptr;
      curr->prev = nullptr;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */