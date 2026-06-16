class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for(int i = n-1; i >= 0; i--){
          digits[i] += 1;
          if (digits[i] <= 9) {
            return digits;
          } else {
            digits[i] = 0;
          }
        }

        vector<int> newSol;
        newSol.push_back(1);
        for(int& digit : digits){
          newSol.push_back(digit);
        }
        return newSol;
    }
};