//stack of pairs where each variable in the stack keeps track of the min in relation to itself. So the first item pushed to the stack would be the min, and if you pushed a new number to the stack, you would check tops min, and compare with that, if the new number is the new min, then don't update the current stack but insert the new variable with the new min in relation to itself. So each variable in the stack will keep a local min in relation to itself and the numbers below it. When a number is reached it will always know the min in relationship to itself and the numbers beneath it.

class MinStack {
public:
    stack<pair<int,int>> min_stack;
    MinStack() {
        
    }
    
    void push(int val) {
        if(min_stack.size() == 0){
          min_stack.push({val,val});
        } else {
          int currMin = min_stack.top().second;
          currMin = min(currMin,val); //set min as new number if needed
          min_stack.push({val,currMin});
        }
    }
    
    void pop() {
        min_stack.pop();
    }
    
    int top() {
      if(min_stack.empty()){
        return -1;
      }
      return min_stack.top().first;
    }
    
    int getMin() {
      if(min_stack.empty()){
        return -1;
      }
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