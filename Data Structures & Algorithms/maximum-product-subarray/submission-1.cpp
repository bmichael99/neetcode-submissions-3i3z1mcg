class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //naive brute force: generate all possible subarrays and check if its the largest product. O(n^2)
        //optimal: kadanes algorithm TC: O(n) SC: O(1)

        int maxProduct = -11; //-10 <= nums[i] <= 10
        int currMax = 1;
        int currMin = 1;

        for(int i = 0; i < nums.size();i++){
          //if current subarray runs into a 0, multiplying by anything else in the current subarray will result in 0, so reset our progress.
          if(nums[i] == 0){
            currMax = 1;
            currMin = 1;
          }
          //save currMax to make sure we use previous currMax in currMin product.
          int temp = currMax;

          //update max product, could either be current num or product of currMax or currMin
          //must include nums[i] as its own option because lets say we have [-1,8]. Both currMax and currMin will be -1 because it's the only number in the array before 8, both result in -8, but 8 on its own is the actual max.
          currMax = max(nums[i],max(nums[i]*currMax,nums[i]*currMin));

          //update min product, could either be current num or product of currMin or currMax
          currMin = min(nums[i],min(nums[i]*currMin,nums[i]*temp));

          maxProduct = max(currMax,maxProduct);
        }

        return maxProduct;
    }
};