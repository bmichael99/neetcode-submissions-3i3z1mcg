class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //use kadanes algorithm. While numbers are positive, it's always benificial to keep adding numbers to the subarray in hopes of it continuing to grow. If the current sub-array sum goes negative, we abandon the subarray for a new subarray that's non-negative.
      int largestSum = INT_MIN;
      int currSum = 0;

      for(int& num: nums){
        currSum += num;
        largestSum = max(largestSum,currSum);
        if(currSum < 0){
          currSum = 0;
        }
      }
      return largestSum;
    }
};