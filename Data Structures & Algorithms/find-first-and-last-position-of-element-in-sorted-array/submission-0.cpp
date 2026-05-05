class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //nums is sorted in ascending order
        //use binary search to find the target, then use binary search to find the start and end
      int n = nums.size();
      int L = 0;
      int R = n-1;
      int indexFound = -1;
      while(L<=R){
        int M = (L+R)/2;

        if(nums[M] > target){
          R = M-1;
        }else if(nums[M] < target){
          L = M+1;
        } else {
          indexFound = M;
          break;
        }
      }
      if(indexFound == -1) return {-1,-1};

      
      L = indexFound;
      R = n-1;
      int right = 0;
      while(L<=R){
        int M = (L+R)/2;

        if(nums[M] > target){
          R = M-1;
        } else if(nums[M] < target){
          L = M+1;
        } else {
          right = M;
          L = M+1;
        }
      }
      

      L = 0;
      R = indexFound;
      int left = 0;
      while(L<=R){
        int M = (L+R)/2;

        if(nums[M] > target){
          R = M-1;
        } else if(nums[M] < target){
          L = M+1;
        } else {
          left = M;
          R = M-1;
        }
      }
      

      return {left,right};
      
    }



};