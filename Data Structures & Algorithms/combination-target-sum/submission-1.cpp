class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        vector<int> currCombination;
        backTracking(0, target, candidates, currCombination, combinations);
        return combinations;
    }

    void backTracking(int i, int target, vector<int>& nums, vector<int>& currCombination, vector<vector<int>>& combinations) {
        if(target <= 0 || i >= nums.size()){
            if(target == 0)
                combinations.push_back(currCombination);
            return;
        }

        //choose num, can use the same num unlimited times.
        for(int j = i; j < nums.size();j++){
            currCombination.push_back(nums[j]);
            backTracking(j,target-nums[j],nums,currCombination,combinations);
            currCombination.pop_back();
        }
        
    }
};