class KthLargest {
public:
//push nums to a max heap, pop k-1 and keep the kth at the top, if we get a number that's greater than kth top than we add it to the maxHeap
//TC: O(nlogn) for constructor, O(logn) for add
//SC: O(k) for storing k scores
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int capacity;
    KthLargest(int k, vector<int>& nums) {
      this->capacity = k;
      for(int& num : nums){
          minHeap.push(num);
      }
      while(minHeap.size() > k) minHeap.pop();
    }
    
    int add(int val) {
      minHeap.push(val);
      while(minHeap.size() > capacity) minHeap.pop();
      return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */