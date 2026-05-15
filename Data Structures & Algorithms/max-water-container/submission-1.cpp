class Solution {
public:
    int maxArea(vector<int>& height) {
      int L = 0;
      int R = height.size()-1;
      int maxSize = 0;

      while(L < R){
        maxSize = max(maxSize,(R-L)*min(height[L],height[R]));
        
        if(height[L] > height[R]){
          R--;
        } else {
          L++;
        }
      }
      return maxSize;
    }
};