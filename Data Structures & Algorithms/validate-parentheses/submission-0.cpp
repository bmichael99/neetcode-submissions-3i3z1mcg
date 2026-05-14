class Solution {
public:
    bool isValid(string s) {
        //open brackets get pushed to a stack, there's a stack for each type of bracket
        //if we find a closed brack we pop from the stack
        //just use a hash map of size 3 that tracks frequency since it's a little cleaner than having 3 stacks
        stack<char> open;

        for(char& c : s){
          if(c == '(' || c == '{' || c == '['){
            open.push(c);
          } else{
            if(open.size() == 0) return false; //pushing closed bracket with no open brackets in stack
            char curr = open.top();
            if(curr == '(' && c == ')'){
              open.pop();
            } else if(curr == '{' && c == '}'){
              open.pop();
            } else if(curr == '[' && c == ']'){
              open.pop();
            } else{
              return false;
            }
          }
        }
      
      return open.size() == 0; //open brackets left unclosed

        
    }
};