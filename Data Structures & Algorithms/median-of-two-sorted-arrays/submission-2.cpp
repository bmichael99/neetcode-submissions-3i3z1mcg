class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      //O(logn)
      vector<int>& A = nums1;
      vector<int>& B = nums2;

      if(A.size() > B.size()){
        swap(A,B);
      }

      int total = A.size()+B.size();
      int half = total/2;
      bool even = total%2 == 0;

      int L = 0;
      int R = A.size();

      while(L <= R){
        int mA = (L+R)/2;
        int mB = half-mA;

        int aLeft = mA-1 >= 0 ? A[mA-1] : INT_MIN;
        int aRight = mA < A.size() ? A[mA] : INT_MAX;
        int bLeft = mB-1 >= 0 ? B[mB-1] : INT_MIN;
        int bRight = mB < B.size() ? B[mB] : INT_MAX;

        if(aLeft <= bRight && bLeft <= aRight){
          return even ? (double)(max(aLeft,bLeft)+min(aRight,bRight))/2 : (double)min(aRight,bRight);
        } else if(aLeft > bRight){
          R = mA-1;
        } else{
          L = mA+1;
        }
      }
      return 0;
    }
};