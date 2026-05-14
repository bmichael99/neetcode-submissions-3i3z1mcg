class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>& A = nums1;
    vector<int>& B = nums2;

    if(A.size() > B.size()){
      swap(A,B);
    }
    int total_size = A.size()+B.size();
    int half = total_size/2;
    int L = 0;
    int R = A.size();
    while(L <= R){
      //left partition of A is up to but not including M
      int M = (L+R)/2;

      int RB = half - M;

      //left is the last value of the left partition
      //right is the first value of the right partition.
      int Aleft = M-1 >= 0 ? A[M-1] : INT_MIN;
      int Aright = M < A.size() ? A[M] : INT_MAX;
      int Bleft = RB-1 >= 0 ? B[RB-1] : INT_MIN;
      int Bright = RB < B.size() ? B[RB] : INT_MAX;

      //the value at the end of each left partition needs to be less than or equal to the first value of the right partition in the opposite array.
      if(Aleft <= Bright && Bleft <= Aright){ //valid case
        if(total_size % 2 == 0){
          return ((double)max(Aleft,Bleft)+(double)min(Aright,Bright))/2;
        }
        return (double)min(Aright,Bright);
      } else if(Aleft > Bright){ //if last value in left partition of A is greater than first value in right partition of B. Then our left partition in A is too big
        R = M-1;
      } else { //too small
        L = M+1;
      }
    }
    return -1;
  }
};