class Solution {
public:
    int trap(vector<int>& height) {
        //two pointer o(1) space complexity: L and R pointer at each side of height, move the pointer that is smaller, keep track of current maxL and maxR. Whichever pointer we moved, that's the spot where we will check how much water it can hold. This works because since we know calculating water is min(maxL[i],maxR[i]) - height[i], we only care about the minimum number really, so if we know that the pointer we're moving is the min and we update that number, it doesn't matter what the other side is or if it's going to get larger, because we know for sure that we calculate with the min wall size because it's smaller than the other side.
        int n = height.size();
        int maxL = 0;
        int maxR = 0;
        int L = 0;
        int water = 0;
        int R = n-1;
        maxL = max(height[L],maxL);
        maxR = max(height[R],maxR);
        while(L < R){
          if(height[L] < height[R]){
            L++;
            maxL = max(height[L],maxL);
            water += maxL - height[L];
          } else{
            R--;
            maxR = max(height[R],maxR);
            water += maxR - height[R];
          }
        }
        return water;
    }
};