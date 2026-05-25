class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      //brute force: starting from each height try to form the largest possible rectangle by expanding in each direction until new rectangles can't be formed, just try to expand the current height if there are neighboring heights of larger size. O(n^2) worst case
      //monotonic increasing stack
      //TC: O(n) to push all heights to stack and pop all heights from stack
      //SC: O(n) worst case where all heights need to be pushed to stack

      stack<pair<int,int>> st; //starting index, height
      int maxArea = 0;

      for(int i = 0; i < heights.size();i++){
        int starting_index = i;
        while(!st.empty() && st.top().second > heights[i]){
          maxArea = max(maxArea,(i-st.top().first)*st.top().second); //we can calculate the area of the popped height by saying the area is the range of values from starting index to the index before this one, (we know that we now have a smaller height so the range does not include the current index, but we know all heights after the popped height were larger (except current)) The range include this index would be R-L+1, but since we're not including this index we just say R-L which is i-startingindex * height of that bar.
          starting_index = st.top().first;
          st.pop();
        }
        st.push({starting_index,heights[i]});
      }
      int R = heights.size()-1;
      while(!st.empty()){
        maxArea = max(maxArea,(R-st.top().first+1)*st.top().second);
        st.pop();
      }
      return maxArea;

    }
};