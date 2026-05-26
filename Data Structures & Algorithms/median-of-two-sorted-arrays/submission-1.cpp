class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //naive brute force: merge the two arrays, return median of the merged array.
        //naive two pointer: maintain a pointer for each array and iterate through each array based on order, stop half way and return median.
        //optimal: binary search for locating the left and right partitions of the array to find the median.

        vector<int>& A = nums1;
        vector<int>& B = nums2;

        if(A.size() > B.size()){ //always make A the smaller array
          swap(A,B);
        }

        int L = 0;
        int R = A.size();
        int total_size = A.size()+B.size();
        int half = total_size/2;

        while(L <= R){
          int M = (L+R)/2; //left partition of A will be up to but not including M
          int M2 = half-M; //left partition of B will be the remaining indexes to make up the merged left partition, where the left and right partitions divide the array down the middle, and the median is in the center.

          int Aleft = M-1 >= 0 ? A[M-1] : INT_MIN;//last index of left partition
          int Aright = M < A.size() ? A[M] : INT_MAX;//first index of right partition
          int Bleft = M2-1 >= 0 ? B[M2-1] : INT_MIN;
          int Bright = M2 < B.size() ? B[M2] : INT_MAX;

          if(Aleft <= Bright && Bleft <= Aright){ //partitions are valid. Left partitions are less than right partitions
            if(total_size % 2 == 0){
              return (double)(max(Aleft,Bleft) + min(Aright,Bright))/2;
            }
            return (double)min(Aright,Bright);
          } else if(Aleft > Bright){
            R = M-1;
          } else{
            L = M+1;
          }
        }
        return 0;
    }
};