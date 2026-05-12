class Solution {
public:
    bool canPartition(vector<int>& nums) {
      //hash set implementation O(n * target) where target is sum of array elements / 2.
      int n = nums.size()-1;
      int total = 0;
      for(int& num : nums){
        total += num;
      }
      if(total%2 != 0) return false;
      int goal = total/2;

      unordered_set<int> sums;
      sums.insert(0);
      unordered_set<int> newSums;
      for(int i = n-1; i >= 0; i--){
        for(auto& sum : sums){
          int newSum = sum+nums[i];
          if(newSum == goal) return true;
          if(newSum < goal) newSums.insert(sum+nums[i]);
        }
        for(auto& newSum : newSums){
          sums.insert(newSum);
        }
      }
      return false;
    }
};