class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //have a stack that we push operands to, if we get a token that's an operator, take the top two operands and complete the expression using the operator. Push the result to the stack. Since we know that we always have a valid RPN passed in, we can just say the solution is the value left in the stack at the end.

        stack<int> operands;

      for(string& token : tokens){
        //if operator
        if(token == "+" || token == "-" || token == "*" || token == "/"){
          int first = operands.top();
          operands.pop();
          int second = operands.top();
          operands.pop();

          if(token == "+"){
            operands.push(second+first);
          } else if(token == "-"){
            operands.push(second-first);
          } else if(token == "*"){
            operands.push(second*first);
          } else if(token == "/"){
            operands.push(second/first);
          }
        } else { //otherwise operand
          int operand = stoi(token);
          operands.push(operand);
        }
      }
      return operands.top();
    }
};