class KthLargest {
public:
    int size;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    KthLargest(int k, vector<int>& nums) {
      this->size = k;
        //maintain a minHeap of size k where values smaller are ignored and values larger are pushed while maintaining the size property
        //Time Complexity: O(nlog(k)) where n is the length of n, since in the worst case we may need to add all nums to the heap if the array was somehow in strictly increasing order. the heap will always be size k so heap operations will be on a heap of size k
        for(int& num : nums){
          add(num);
        }


    }
    
    int add(int val) {
        if(minHeap.size() < this->size){
          minHeap.push(val);
          return minHeap.top();
        }

        minHeap.push(val);
        minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */