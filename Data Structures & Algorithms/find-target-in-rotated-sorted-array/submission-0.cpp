class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Find the rotation point via binary search. If nums[0] < nums[n-1] then the array is not rotated.
        //do binary search on the part of the array that contains target
        int minIndex = findMin(nums,target);
        int n = nums.size();
        int L = 0;
        int R = n-1;

        if(minIndex == 0){
            L = 0;
            R = n-1;
        } else if(target >= nums[0] && target <= nums[minIndex-1]){
            L = 0;
            R = minIndex-1;
        } else if(target >= nums[minIndex] && target <= nums[n-1]){
            L = minIndex;
            R = n-1;
        }

        while(L <= R){
            int M = (L+R)/2;

            if(nums[M] < target){
                L = M+1;
            } else if(nums[M] > target){
                R = M-1;
            } else {
                return M;
            }
        }
        
        return -1;
    }

    int findMin(vector<int> nums, int target){
        int L = 0;
        int R = nums.size()-1;
        int minIndex= 0;
        while(L <= R){
          int M = (L+R)/2;
          if(nums[M] < nums[0]){
            if(nums[M] < nums[minIndex]){
                minIndex = M;
            }
            R = M-1;
          }else {
            L = M+1;
          }
        }
        return minIndex;
    }
};