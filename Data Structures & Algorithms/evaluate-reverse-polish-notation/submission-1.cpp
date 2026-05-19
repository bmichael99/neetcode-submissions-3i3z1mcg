class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //push operands to stack, if we run into an operator pop the top two numbers from the stack and use the operator on them. second number popped is the left operand.
        //Time complexity: O(n)
        //Space complexity: O(n)
        stack<int> operands;
        for(string& token : tokens){
          if(token == "+" || token == "-" || token == "*" || token == "/"){
            int second = operands.top();
            operands.pop();
            int first = operands.top(); 
            operands.pop();

            if(token == "+") operands.push(first+second);
            else if(token == "-") operands.push(first-second);
            else if(token == "*") operands.push(first*second);
            else if(token == "/") operands.push(first/second);
          } else {
            operands.push(stoi(token));
          }
        }
        return operands.top();
    }
};