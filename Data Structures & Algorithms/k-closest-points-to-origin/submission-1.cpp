class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //push distance from 0,0 to minheap, return k smallest
        //nlogn where n is the number of points, logn for heap operations
        //return the actual points so we need to store index in minHeap

        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> minHeap;
        //don't forget to include double for precision.

        for(int i = 0; i < points.size();i++){
          minHeap.push({(double)sqrt(pow(points[i][0],2) + pow(points[i][1],2)), i});
        }
        vector<vector<int>> sol;
        while(k > 0){
          sol.push_back(points[minHeap.top().second]);
          minHeap.pop();
          k--;
        }
        return sol;
    }
};