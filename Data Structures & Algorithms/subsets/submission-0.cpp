class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currSubset;
        backTracking(0,nums,currSubset,subsets);
        return subsets;
    }

    void backTracking(int i, vector<int>& nums, vector<int>& currSubset, vector<vector<int>>& subsets){
        if(i >= nums.size()){
            subsets.push_back(currSubset);
            return;
        }

        //choose num
        currSubset.push_back(nums[i]);
        backTracking(i+1,nums,currSubset,subsets);
        currSubset.pop_back(); //backtrack

        //skip num
        backTracking(i+1,nums,currSubset,subsets);
    }
};