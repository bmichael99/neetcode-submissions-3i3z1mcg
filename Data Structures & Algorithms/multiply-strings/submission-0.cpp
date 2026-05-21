class Solution {
public:
    string multiply(string num1, string num2) {
        //multiply the two strings together as if we are doing long multiplication normally
        //TC: O(n^2), we need to multiply each index of one string against all indexes of the other, so n*n
        //SC: O(n)
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> sol(n1+n2,0);
        if(sol.empty()) return "";

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i = 0; i < n1; i++){
          for(int j = 0; j < n2; j++){
            //i+j allows us to place partial products in their correct place.
            sol[i+j] += ((num2[j]-'0')*(num1[i]-'0'));
            sol[i+j+1] += sol[i+j]/10; //move carry to index after curr
            sol[i+j] %= 10; //number in the ones place is stored in curr position, number in tens place is carried over above
          }
        }
      
        while(sol.back() == 0){
          sol.pop_back();
        }

        
        string sol_str;
        for(int i = sol.size()-1; i >= 0; i--){
          sol_str.push_back((sol[i] + '0')); //convert ints to chars and add to solution string
        }


        return sol_str;
    }
};