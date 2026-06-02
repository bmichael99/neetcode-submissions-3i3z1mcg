class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //monotonic increasing stack.
        //if a number gets pushed to the stack and the top number is larger, calculate the size of the square from the current index and the height in he stack by taking the height of the current smaller height (the min of the two), and multiplying by the width between the current index and the index in which that height was inserted. You can garuntee that this square exists since we maintain a monotonic increasing stack meaning there will only be larger squares in front of one that's in the stack, if there was ever a smaller height in front of a height in the stack, it already would've been popped.
        //Time complexity: O(n), we calculate the max area of rectangles as we iterate through heights
        //Space complexity: O(n), stack can be of size n in worst case where input array is strictly increasing.

        stack<pair<int,int>> mono; //height,index

        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
          int smallest_index = i;
          while(!mono.empty() && mono.top().first > heights[i]){
            //calculate area from the farthest index that was at least the current stack height to the index before the current height. We do not include the current height in the calculation, instead we use the height in the stack.
            maxArea = max(maxArea,mono.top().first*(i-mono.top().second));
            smallest_index = mono.top().second;
            mono.pop();
          }
          mono.push({heights[i],smallest_index});
        }
        // in the case where leading up the end of the array we only had strictly increasing heights, we need to calculate the area from each square until the end of the array. We use range here (R-L+1) because we include values from the current height in stack up until the end of the array
        int R = heights.size()-1;
        while(!mono.empty()){ 
          maxArea = max(maxArea,(R-mono.top().second+1)*mono.top().first);
          mono.pop();
        }

        return maxArea;
    }
};