class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0;
        int R = numbers.size()-1;
        while(L < R){
            if(numbers[L] + numbers[R] < target){
                L++;
            } else if(numbers[L] + numbers[R] > target){
                R--;
            } else {
                return {L+1,R+1}; //solution should be 1-indexed, so add 1 to L and R
            }
        }
        return {};
    }
};