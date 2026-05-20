class Node{
public:
  Node* next;
  Node* prev;
  int val;
  int key;
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
    Node* head;
    Node* tail;
    unordered_map<int,Node*> cache; //key -> node
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->head = nullptr; //MRU
        this->tail = nullptr; //LRU
    }
    
    int get(int key) {
        if(cache.contains(key)){
          useNode(cache[key]);
          return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(size >= capacity && !cache.contains(key)){
          cache.erase(this->tail->key);
          removeTail();
          size--;
        }

        if(!cache.contains(key)){
          cache[key] = new Node(key, value);
          insertHead(cache[key]);
          size++;
        } else {
          cache[key]->val = value;
          useNode(cache[key]);
        }

        
    }

    void useNode(Node* curr){
      if(curr == this->head){
        return;
      }
      else if(curr == this->tail){
        removeTail();
        insertHead(curr);
      } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        insertHead(curr);
      }
    }

    void insertHead(Node* curr){
      if(this->head == nullptr){
        this->head = curr;
        this->tail = curr;
        return;
      }
      curr->next = this->head;
      this->head = curr;
      curr->next->prev = curr;
      this->head->prev = nullptr;
    }

    void removeTail(){
      if(this->tail == this->head){
        this->tail = nullptr;
        this->head = nullptr;
      } else {
        Node* temp = this->tail;
        this->tail = this->tail->prev;
        temp->prev = nullptr;
        this->tail->next = nullptr;
      }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */