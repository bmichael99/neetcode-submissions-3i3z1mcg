class Solution {
public:
    int findMin(vector<int>& nums) {
        //do binary search to find the min. Compare against nums[0] to find pivot.

        int L = 0;
        int R = nums.size()-1;
        int minNum = nums[0];

        while(L <= R){
          int M = (L+R)/2;
          if(nums[0] > nums[M]){
            minNum = min(minNum,nums[M]);
            R = M-1;
          } else {
            L = M+1;
          }
        }
        return minNum;
    }
};