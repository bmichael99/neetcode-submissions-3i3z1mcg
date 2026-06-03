class MinStack {
public:
    //stack where each layer keeps track of its relative min.
    //TC: O(n)
    //SC: O(n)
    stack<pair<int,int>> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        int min_num = val;
        if(!min_stack.empty()){
          min_num = min(min_stack.top().second,min_num);
        }
        min_stack.push({val,min_num});
    }
    
    void pop() {
        min_stack.pop();
    }
    
    int top() {
        return min_stack.top().first;
    }
    
    int getMin() {
        return min_stack.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */