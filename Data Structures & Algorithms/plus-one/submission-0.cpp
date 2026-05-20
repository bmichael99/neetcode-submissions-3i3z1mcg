class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      //iterate through digits in reverse order, add 1, if there's no carry over we can stop immediately. Continue while there is carry overs and handle carry over arithmetic while iterating through the array in reverse order.
      //you could just always make a new vector, but I decided to do it like this
      //TC: O(2n) worst case = O(n)
      //SC: O(n) worst case

      for(int i = digits.size()-1; i >= 0; i--){
        if(digits[i] < 9){
          digits[i] += 1;
          return digits;
        } else {
          digits[i] = 0;
        }
      }

      //if we're here we need to make a new vector with a leading 1 for the carry over.
      vector<int> sol;
      sol.push_back(1);
      for(int& d : digits){
        sol.push_back(d);
      }
      return sol;
      
    }
};