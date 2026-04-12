class Solution {
public:
    bool canPartition(vector<int>& nums) {
        //naive bruteforce: generate all possible subsets using backtracking, 
        //simply generate the second subset using the numbers not in the current subset.
        //after each generated subset compare the two subsets

        // 
        int total = 0;
        for(int& num: nums){
            total += num;
        }
        if(total % 2 == 1){
            return false;
        }
        vector<vector<int>> cache(nums.size()+1, vector<int>(total/2 +1,-1));
        int result = backTracking(0,nums,total/2,cache);
        return result == -1 ? false : result;
    }

    int backTracking(int i, vector<int>& nums, int target,vector<vector<int>>& cache){
        if(i >= nums.size() || target <= 0){
            if(target == 0){
                return true;
            }
            return false;
        }
        if(cache[i][target] != -1){
            return cache[i][target];
        }

        //include number
        
        if(backTracking(i+1,nums,target-nums[i],cache)){
            cache[i][target] = true;
            return cache[i][target];
        }

        //skip number
        if(backTracking(i+1,nums,target,cache)){
            cache[i][target] = true;
            return cache[i][target];
        }

        cache[i][target] = false;
        return cache[i][target];
    }
};