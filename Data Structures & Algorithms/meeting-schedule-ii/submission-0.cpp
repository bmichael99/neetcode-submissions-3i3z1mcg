class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        //if two intervals overlap, another conference room will be required. 
        //if an interval does not overlap with any others, we will not need an extra conference room.

        //sort intervals by starting time, push end times to a minHeap and give the opportunity to pop at each interval if current starting time is > minHeap.top() ending time, the number of conference rooms being used is the size of the minHeap after popping meetings that have possibly ended.
      //remember edge case, matching interval[i][start] and interval[i+1][end] times does not count as an overlap here
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int minRooms = 0;
        for(Interval& interval : intervals){
          while(!minHeap.empty() && minHeap.top() <= interval.start){
            minHeap.pop();
          }
          minHeap.push(interval.end);
          minRooms = max(minRooms,(int)minHeap.size());
        }
        return minRooms;
    }
};