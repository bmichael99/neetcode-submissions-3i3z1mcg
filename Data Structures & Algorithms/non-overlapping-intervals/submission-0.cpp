class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //naive Bruteforce O(n^2): go from each interval in intervals and scan the rest of the array and count how many intervals overlap 
        //less naive O(nlogn): sort intervals and delete the overlapping interval with the largest end value.
        //If two intervals overlap, we must remove one of them, there is no case where removing a third interval would stop the first two from overlapping. In this greedy approach we remove the one that has the largest end value, to hopefully prevent it form overlapping with more intervals.

        sort(intervals.begin(),intervals.end());

        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < intervals.size();i++){
          if(prevEnd > intervals[i][0]){
            count++; 
            prevEnd = min(prevEnd,intervals[i][1]); //delete the overlapping interval with the largest end value
          } else{
            prevEnd = intervals[i][1];
          }
        }
      return count;
    }
};