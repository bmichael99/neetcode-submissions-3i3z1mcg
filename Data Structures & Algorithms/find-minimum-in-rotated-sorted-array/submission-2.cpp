class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0;
        int R = nums.size()-1;
        int smallest = nums[0];

        while(L <= R){
          int M = (L+R)/2;

          if(nums[M] < nums[0]){
            R = M-1;
          } else if(nums[M] >= nums[0]){
            L = M+1;
          }
          smallest = min(nums[M],smallest);
        }
        return smallest;
    }
};