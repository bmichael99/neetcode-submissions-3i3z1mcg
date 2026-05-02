class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //naive solution is to create all combinations of max size 3 where the sum is 0. This is a backtracking solution that would be 2^n.
        //sort the input and loop through nums, create a window surrounding the current index, the value to the left of the index will have a L pointer and the value to the right of the index will have a R pointer.
        //since our input is sorted we can move the pointers in the direction that will get us closer to 0, if we run into the case where getting to 0 will be impossible then we move onto the next index, but don't stop until we get to that point, as there could possible be multiple valid triplets starting from the current index.

        sort(nums.begin(),nums.end());
        vector<vector<int>> triplets;
        for(int i = 0; i < nums.size();i++){
          if(nums[i] > 0) break;
          int L = i+1;
          int R = nums.size()-1;

          if((i-1 >= 0) && (nums[i] == nums[i-1])){
            continue;
          }
          while(L < R){
            if((nums[i] + nums[L] + nums[R]) > 0){
              R--;
            } else if ((nums[i] + nums[L] + nums[R]) < 0){
              L++;
            }else{
              triplets.push_back({nums[i],nums[L],nums[R]});
              L++;
              R--;
              while(L < R && nums[L] == nums[L-1]){ //make sure this is inside the else, we only do this if we find a solution to avoid finding the same solution twice, we don't want to skip over duplicates of L otherwise because we may want R to use the same number (not index) as L to create a solution.
                L++;
              }
            }
          }
        }
        return triplets;
    }
};