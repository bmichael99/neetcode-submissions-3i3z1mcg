class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        //if there are overlapping intervals, return false.
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int i = 0;
        while(i+1 < intervals.size()){
          if(intervals[i].end > intervals[i+1].start){
            return false;
          }
          i++;
        }
        return true;
    }
};