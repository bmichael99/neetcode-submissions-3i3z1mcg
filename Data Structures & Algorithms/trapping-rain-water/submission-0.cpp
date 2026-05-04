
class Solution {
public:
    int trap(vector<int>& height) {
          int n = height.size();
          vector<int> maxL(n,0);
          vector<int> maxR(n,0);
          int water = 0;
          maxL[0] = height[0];
          maxR[n-1] = height[n-1];
          for(int i = 1; i < height.size()-1;i++){
            maxL[i] = max(height[i],maxL[i-1]);
            maxR[n-1-i] = max(height[n-i-1],maxR[n-i]);
          }

          for(int i = 1; i < height.size()-1; i++){
            int curr = min(maxL[i-1],maxR[i+1]) - height[i];
            if(curr > 0) water += curr;
          }
          return water;

    }
};