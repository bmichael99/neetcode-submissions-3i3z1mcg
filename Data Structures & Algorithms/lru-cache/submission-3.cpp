class Node {
public:
  int val;
  int key;
  Node* next;
  Node* prev;
  Node(int key,int val){
    this->val = val;
    this->key = key;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class LRUCache {
public:
    int capacity;
    int size;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> cache;
    LRUCache(int capacity) {
      this->capacity = capacity;
      this->size = 0;
      this->head = nullptr;
      this->tail = nullptr;
    }
    
    int get(int key) {
        //recently used keys go to head, least used goes to tail.
      if(cache.contains(key)){
        useNode(cache[key]);
        return cache[key]->val;
      }
      // If cache does not contain key
      return -1;
        
    }
    
    void put(int key, int value) {
        if(cache.contains(key)){
          cache[key]->val = value;
          useNode(cache[key]);
          return;
        }
        if(this->size == this->capacity){
          cache.erase(this->tail->key);
          removeNode(this->tail);
          this->size--;
        }
        cache[key] = new Node(key,value);
        insertHead(cache[key]);
        this->size++;
    }

    void useNode(Node* curr){
      if(curr == this->head){
        return;
      } else {
        removeNode(curr);
        insertHead(curr);
      }
    }

    void insertHead(Node* curr){
      if(!this->head && !this->tail){
        this->head = curr;
        this->tail = curr;
      } else {
        this->head->prev = curr;
        curr->next = this->head;
        this->head = curr;
      }
    }

    void removeNode(Node* curr){
      if(curr == this->head && curr == this->tail){
        this->head = nullptr;
        this->tail = nullptr;
        curr->next = nullptr;
        curr->prev = nullptr;
      } else if(curr == this->head){
        this->head = this->head->next; //set head to node after head
        curr->next = nullptr; //set old head next to nullptr
        this->head->prev = nullptr; //set new head prev to nullptr
      }else if(curr == this->tail){
        this->tail = this->tail->prev;
        curr->prev = nullptr;
        this->tail->next = nullptr;
      } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = nullptr;
        curr->prev = nullptr;
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */