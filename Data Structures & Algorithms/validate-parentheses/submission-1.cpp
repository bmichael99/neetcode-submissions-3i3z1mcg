class Solution {
public:
    bool isValid(string s) {
        stack<int> open;

        for(char& c : s){
          if(c == '(' || c == '{' || c == '['){
            open.push(c);
          } else if(!open.empty()){
            if(c == ')' && open.top() == '('){
              open.pop();
            } else if(c == '}' && open.top() == '{'){
              open.pop();
            } else if(c == ']' && open.top() == '['){
              open.pop();
            } else {
              return false;
            }
          } else {
            return false;
          }
        }
        return open.size() == 0;
    }
};