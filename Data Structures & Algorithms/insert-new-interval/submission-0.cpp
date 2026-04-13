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
        //empty intervals case
        if(intervals.empty()){
            sol.push_back(newInterval);
            return sol;
        }

        //newIntervals insert beginning case
        if(newInterval[end] < intervals[0][start]){
            sol.push_back(newInterval);
        }

        int i = 0;
        while(i < n){
            vector<int> interval = intervals[i];
            if(!doesIntersect(interval, newInterval)){
                sol.push_back(interval);

                //newInterval not overlapping but between two intervals case
                if(i+1 < n && newInterval[start] > interval[end] && newInterval[end] < intervals[i+1][start]){
                    sol.push_back(newInterval);
                }
                i++;
                continue;
            }else{
                int startOverlap = min(interval[start],newInterval[start]);
                int endOverlap = max(interval[end],newInterval[end]);
                while(i < n && doesIntersect(interval, newInterval)){
                    startOverlap = min(startOverlap,interval[start]);
                    endOverlap = max(endOverlap, interval[end]);
                    i++;
                    if(i < n)
                        interval = intervals[i];
                }
                sol.push_back({startOverlap,endOverlap});
            }
        }

        //newIntervals insert end case
        if(newInterval[start] > intervals[n-1][end]){
            sol.push_back(newInterval);
        }

        return sol;
    }

    bool doesIntersect(vector<int>& interval, vector<int>& newInterval){
        if(newInterval[start] >= interval[start] && newInterval[start] <= interval[end] //start of new interval intersects interval
        || newInterval[end] >= interval[start] && newInterval[end] <= interval[end] //end of new interval intersects interval
        || interval[start] >= newInterval[start] && interval[start] <= newInterval[end] //start of interval intersects new interval
        || interval[end] >= newInterval[start] && interval[end] <= newInterval[end]){ //end of interval intserects new interval
            return true;
        }
        return false;
    }
};