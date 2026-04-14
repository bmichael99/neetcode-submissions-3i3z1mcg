class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int n = intervals.size();
        int i = 0;
        vector<vector<int>> sol;

        while(i+1 < n){
          if(intervals[i][1] < intervals[i+1][0]){
            sol.push_back(intervals[i]);
            i++;
            continue;
          }
          int startOverlapping = min(intervals[i][0],intervals[i+1][0]);
          int endOverlapping = max(intervals[i][1],intervals[i+1][1]);
          //make sure the check uses endOverlapping here because we don't want to just compare the end of the next interval and the start of the next+1 interval, say the first overlapping interval has a very large number or any interval in the overlap, you want to use the largest number for comparison as that represents the total range.
          while(i+1 < n && endOverlapping >= intervals[i+1][0]){
            startOverlapping = min(startOverlapping,intervals[i+1][0]);
            endOverlapping = max(endOverlapping,intervals[i+1][1]);
            i++;
          }
          sol.push_back({startOverlapping,endOverlapping});
          i++;
        }
        if(i < n) sol.push_back(intervals[i]);
        return sol;
    }
};