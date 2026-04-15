class Solution {
public:
    bool canJump(vector<int>& nums) {
        //naive solution: backtracking where the range of the jump length is your choices, O^n where n is the average jump length. Do not jump past the end of the array.

        //non-naive but still bad: always jump to the position that will let you jump the farthest again, so you have the best range of options. Since we can jump any length within our max jump length we just need to make sure we don't end up in an index with a length of 0. jump length of 0 is the only thing that can stop us from reaching the end of the array. O(n^2)
        //optimal solution: instead of jumping then scanning for the next step to jump to we could do a single O(n) pass by keeping track of our current remaining steps and if we reach a number while we still have steps that's bigger than our current steps than we replace our remaining steps with the new large number. return false if we run out of steps before reaching the last index
        int remainingSteps = 0;
        for(int i = 0; i < nums.size();i++){
          remainingSteps = max(remainingSteps,nums[i]);
          if(i+remainingSteps >= nums.size()-1) return true; //return true if we can reach last index from i
          if(remainingSteps == 0) return false;
          remainingSteps--;
        }
        return true;
    }
};