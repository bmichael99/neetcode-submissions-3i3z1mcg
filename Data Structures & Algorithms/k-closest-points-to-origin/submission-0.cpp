class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //minHeap problem where we calculate the distance of each point to 0,0, push the distance to minHeap, pop k closest points.
        //TC: O(nlogn) where n is the input list we iterate through and logn is the time for pushing to minHeap.
        //SC: O(n)
        
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> minHeap;
        for(int i = 0; i < points.size();i++){
          int x1 = points[i][0];
          int x2 = points[i][1];

          minHeap.push({(double)sqrt(pow(x1,2) + pow(x2,2)),i});
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