class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      //brute force: Iterate through array, calculate product of all element except current.
        //optimal: Prefix Product problem.
        vector<int> answer;
        int n = nums.size();
        vector<int> prefix (n,1);
        vector<int> suffix (n,1);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

      for(int i = 1; i < n;i++){
        prefix[i] = nums[i] * prefix[i-1];
        suffix[n-1-i] = nums[n-1-i] * suffix[n-i];
      }
      
      for(int i = 0; i < n;i++){
        if(i == 0){
          answer.push_back(suffix[i+1]);
        } else if(i == n-1){
          answer.push_back(prefix[i-1]);
        } else {
          answer.push_back(prefix[i-1] * suffix[i+1]);
        }

      }
      return answer;
    }
};