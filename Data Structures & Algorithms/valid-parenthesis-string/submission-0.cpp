class Solution {
public:
    bool checkValidString(string s) {
        //when we find an open paranthesis push it to the stack along with its index, same thing with *. If we run into a closed paranthesis than pop from open, if open is empty than pop from any, if both are empthy than return false.
        //If there are open left at the end of the traversal than we can try to validate them by removing from any as closed paranthesis. In order for an any to be a valid closed paranthesis for an open paranthesis, the index of the open paranthesis needs to be before the index of the any.
        //The top of the stack will be the highest index open and the highest index any, so if open is larger than star at any point return false, no point searching the any stack for a larger index.
        stack<pair<char,int>> open;
        stack<pair<char,int>> any;
        for(int i = 0; i < s.length();i++){
            if(s[i] == '('){
                open.push({s[i],i});
            } else if(s[i] == '*'){
                any.push({s[i],i});
            } else{
                if(!open.empty()){
                    open.pop();
                } else if(!any.empty()){
                    any.pop();
                } else {
                    return false;
                }
            }
        }
        if(any.size() < open.size()){
            return false;
        }

        while(!open.empty() && !any.empty()){
            if(open.top().second < any.top().second){
                open.pop();
                any.pop();
            } else{
                return false;
            }
        }
        
        return open.size() == 0;
    }
};