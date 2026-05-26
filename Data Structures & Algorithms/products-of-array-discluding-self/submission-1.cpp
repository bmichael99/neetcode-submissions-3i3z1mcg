class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //optimal: prefix product problem, two arrays. One array multiplies numbers in order from left to right, the other multiplies numbers in order from right to left. O(n)
        //brute force: multiply all other numbers except the current for each index. O(n^2)
      int n = nums.size();
      vector<int> suffix(n,1);
      vector<int> prefix(n,1);
      vector<int> answer(n,1);
      prefix[0] = nums[0];
      suffix[n-1] = nums[n-1];

      for(int i = 1; i < nums.size();i++){
        prefix[i] = prefix[i-1]*nums[i];
        suffix[n-1-i] = suffix[n-i]*nums[n-i-1];
      }
      answer[0] = suffix[1];
      answer[n-1] = prefix[n-2];
      for(int i = 1; i < nums.size()-1;i++){
        answer[i] = prefix[i-1] * suffix[i+1];
      }
      return answer;
    }
};