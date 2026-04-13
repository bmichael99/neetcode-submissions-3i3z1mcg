class Solution {
public:
    int start = 0;
    int end = 1;
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //use binary search to find where to insert this interval, I didn't do that here but it's an optimization.

        //an interval overlaps simply if the start or end of the new interval overlaps with the current interval 
        //OR
        //if the start or end of the current interval overlaps with the new interval

        int n = intervals.size();
        vector<vector<int>> sol;
        
        int i = 0;
        //continue pushing to sol until we find where newInterval would go
        while(i < n && intervals[i][end] < newInterval[start]){
            sol.push_back(intervals[i]);
            i++;
        }

        //combine intervals
        while(i < n && intervals[i][start] <= newInterval[end]){
            newInterval[start] = min(newInterval[start],intervals[i][start]);
            newInterval[end] = max(newInterval[end],intervals[i][end]);
            i++;
        }
        sol.push_back(newInterval);

        //finish pushing to sol
        while(i < n){
            sol.push_back(intervals[i]);
            i++;
        }

        return sol;
    }


};