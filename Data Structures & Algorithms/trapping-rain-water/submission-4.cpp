class Solution {
public:
    int trap(vector<int>& height) {
        //optimal 1: keep track of maxL and maxR arrays, for each position in the elevation map, the amount of water trapped is min(maxL,maxR) - height[i]. where the walls of maxL and maxR form the container holding water, and the min sets how much water can be contained.
        //optimal 2: you can use two pointers maxL and maxR, we only care about the minimum wall to determine the amount of water at the current position. so you can determine the amount of water at a position by knowing the min wall height up to the current position. Always move the pointer with the smallest elevation and calculate water at that point since u know it's the minimum.
        
        //optimal 1: TC: O(n) SC: O(n)
        //optimal 2: TC: O(n) SC: O(1)
        int n = height.size();
        int maxL = height[0];
        int maxR = height[n-1];
        int L = 1;
        int R = n-2;
        int water = 0;
        while(L <= R){
          if(maxL < maxR){
            maxL = max(maxL,height[L]);
            water += maxL - height[L];
            L++;
          } else {
            maxR = max(maxR,height[R]);
            water += maxR - height[R];
            R--;
          }
        }
        return water;
    }
};