class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //use binary search to find the row that contains target
        //use binary search to find the target within row

        int n = matrix.size();
        int L = 0;
        int R = n-1;

        int rn = matrix[0].size();
        int row = 0;

        while(L<=R){
          int M = (L+R)/2;
          //if first value in array is larger than target, search to the left
          if(matrix[M][0] > target){
            R = M-1;
          } else if(matrix[M][rn-1] < target){ //if last value in the array is smaller than target,
            L = M+1;
          } else{
            row = M;
            break;
          }
        }

        L = 0;
        R = rn-1;

        while(L <= R){
          int M = (L+R)/2;

          if(matrix[row][M] > target){
            R = M-1;
          } else if(matrix[row][M] < target){
            L = M+1;
          } else {
            return true;
          }
        }

        return false;
    }
};