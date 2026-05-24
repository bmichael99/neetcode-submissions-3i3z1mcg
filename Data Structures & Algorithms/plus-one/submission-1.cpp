class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      //add 1, if we have a carry keep adding one, otherwise return digits after adding 1
      //if we still have carry after traversing through the array of digits, we need to make a new array with a leading 1 and add digits
      //TC: O(n) to iterate through all digits in worst case
      //SC: O(n) worst case, otherwise we edit original array
      for(int i = digits.size()-1; i >= 0;i--){
        digits[i] += 1;
        if(digits[i] > 9){
          digits[i] = 0;
        } else {
          return digits;
        }
      }

      vector<int> sol = {1};
      for(int& digit : digits){
        sol.push_back(digit);
      }
      return sol;
    }
};