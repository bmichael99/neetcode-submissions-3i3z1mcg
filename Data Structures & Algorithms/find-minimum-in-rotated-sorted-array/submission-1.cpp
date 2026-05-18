class Solution {
public:
    int findMin(vector<int>& nums) {
      //use binary search. If number is greater than num[0] than move right, if number is smaller than num[0] than move left.

      int L = 0;
      int R = nums.size()-1;
      int minNum = nums[0];

      while(L <= R){
        int M = (L+R)/2;

        if(nums[M] < nums[0]){
          minNum = nums[M];
          R = M-1;
        } else {
          L = M+1;
        }
      }
      return minNum;
    }
};