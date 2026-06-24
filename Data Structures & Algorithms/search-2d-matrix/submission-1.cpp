class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //2d matrix where all arrays are in sorted order, use binary search to search through Matrix
        //TC: O(logn) SC :O(1)
        //first find array that would contain target
        int T = 0;
        int B = matrix.size()-1;
        int L = 0;
        int R = matrix[0].size()-1;
        int M = 0;
        while(T <= B){
          M = (T+B)/2;

          
          if(matrix[M][L] > target){
            B = M-1;
          } else if(matrix[M][R] < target){
            T = M+1;
          } else { // if matrix[M][L] <= target && matrix[M][R] >= target aka target is in this array
            break;
          }
        }
        if(matrix[M][L] > target || matrix[M][R] < target){
          return false;
        }

        while(L <= R){
          int M2 = (L+R)/2;

          if(matrix[M][M2] > target){
            R = M2-1;
          } else if(matrix[M][M2] < target){
            L = M2+1;
          } else {
            return true;
          }
        }
        return false;

    }
};