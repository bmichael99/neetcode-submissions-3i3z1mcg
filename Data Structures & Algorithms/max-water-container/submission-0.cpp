class Solution {
public:
  int maxArea(vector<int>& height) {
    //naive: calculate the size of all possible containers starting from each index O(n^2)
    //optimal O(n): two pointer problem where we only move the pointer that's smaller, calculate the area at each point
    //explanation of optimal: we start from the largest possible width since we know that will result in the largest possible area, if one side of the container is smaller than the other, than we know that if we move the smaller side we could potentially end up with a larger container, this will allow us to find the largest possible container size in O(n) time.


    int L = 0;
    int R = height.size()-1;
    int maxArea = 0;

    while(L < R){
      maxArea = max(maxArea, (R-L)*min(height[L],height[R]));
      if(height[L] > height[R]){
        R--;
      }else{
        L++;
      }
    }
    return maxArea;
  }
};