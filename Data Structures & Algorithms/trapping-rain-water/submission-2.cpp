class Solution {
public:
  int trap(vector<int>& height) {
    //brute force: Time Complexity: O(n^2) find maximum height to the left of the elemtn, find maximum height to the right of the element, take the minimum of both maximums and subtract current height.
    //optimal: two arrays, maxL maxR, you calculate the highest elevation at each index starting from each side of the array. The amount of water in each index is min(maxL,maxR) - height[i].
    //Time complexity: O(1), space complexity O(n)
    int n = height.size();
    vector<int> maxL(n,0);
    vector<int> maxR(n,0);
    maxL[0] = height[0];
    maxR[n-1] = height[n-1];
    int water = 0;

    for(int i = 1; i < n;i++){
      maxL[i] = max(height[i],maxL[i-1]);
      maxR[n-1-i] = max(height[n-1-i],maxR[n-i]);
    }

    for(int i = 1; i < n-1;i++){
      water += min(maxR[i],maxL[i]) - height[i]; //using the current index for checking maxL and maxR works because if the current index is the min max, then - height[i] will be 0. If you use the max of the indexes to the left and right then you will need to make sure water isn't negative because the current index could be taller than the walls containing it.
    }
    return water;
  }
};