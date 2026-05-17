class Solution {
public:
  int trap(vector<int>& height) {
    //brute force: Time Complexity: O(n^2) find maximum height to the left of the elemtn, find maximum height to the right of the element, take the minimum of both maximums and subtract current height.
    //optimal: Calculate maxL and maxR with two pointers. We only care about which side has the minimum wall height since that's what determines the amount of water in the current tile. Iterate the pointer with the smallest max The amount of water in each index is min(maxL,maxR) - height[i].
    //Time complexity: O(n), space complexity O(1)
    int n = height.size();
    //edges cannot contain water.
    int L = 1;
    int R = n-2;
    int maxL = height[0];
    int maxR = height[n-1];
    int water = 0;
    while(L <= R){
      if(maxL < maxR){
        maxL = max(height[L],maxL);
        water += maxL - height[L];
        L++;
      } else{
        maxR = max(height[R],maxR);
        water += maxR - height[R];
        R--;
      }
    }

    return water;
  }
};