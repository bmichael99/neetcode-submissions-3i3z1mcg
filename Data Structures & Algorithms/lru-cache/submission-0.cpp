class Node {
public:
  Node* next;
  Node* prev;
  int val;
  int key;

  Node(int key, int val){
    this->val = val;
    this->key = key;
    this->next = nullptr;
    this->prev = nullptr;
  }
};


//LRU should be at tail, most recently used items are moved to head/inserted at head.
class LRUCache {
public:
  Node* head;
  Node* tail;
  int capacity;
  int size;
  unordered_map<int,Node*> cache; //map key to node
  LRUCache(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
  }
  
  int get(int key) {
    if(!cache.contains(key)){
      return -1;
    }
    Node* getNode = cache[key];

    removeNode(getNode);
    insertHead(getNode);

    return getNode->val;
  }
  
  void put(int key, int value) {
    if(size == capacity && !cache.contains(key)){
      Node* removed = removeTail();
      cout << removed->key << endl;
      cache.erase(removed->key);
      size--;
    }

    if(cache.contains(key)){
      cache[key]->val = value;
      removeNode(cache[key]);
      insertHead(cache[key]);
    } else {
      Node* newNode = new Node(key,value);
      cache[key] = newNode;
      insertHead(newNode);
      this->size++;
    }
  }

private:
  Node* removeTail(){
    Node* temp = this->tail;
    if(this->tail == this->head){
      this->tail = nullptr;
      this->head = nullptr;
      return temp;
    }

    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    return temp;
  }

  void removeHead(){
    if(this->tail == this->head){
      this->tail = nullptr;
      this->head = nullptr;
      return;
    }

    Node* temp = this->head;
    this->head = this->head->next;
    this->head->prev = nullptr;
  }

  void insertHead(Node* newNode){
    if(!this->tail && !this->head){
      this->tail = newNode;
      this->head = newNode;
      return;
    }

    //incase of reusing node
    newNode->next = nullptr;
    newNode->prev = nullptr;

    this->head->prev = newNode;
    newNode->next = this->head;
    this->head = newNode;
  }

  void removeNode(Node* remove){
    if(this->head == remove && this->tail == remove){
      this->tail = nullptr;
      this->head = nullptr;
    }else if(this->head == remove){
      removeHead();
    }else if(this->tail == remove){
      removeTail();
    } else {
      remove->prev->next = remove->next;
      remove->next->prev = remove->prev;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */