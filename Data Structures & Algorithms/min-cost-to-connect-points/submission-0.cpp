class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        //minimum spanning tree. Don't bother building an adjacency list since we know that we will explore the possibility of every point reaching all other points.
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        unordered_set<int> visited;
        int sol = 0;

        minHeap.push({0,0});

        while(!minHeap.empty() && visited.size() < points.size()){
          if(visited.contains(minHeap.top().second)){
            minHeap.pop();
            continue;
          }
          int w1 = minHeap.top().first;
          sol += w1;
          vector<int>& p1 = points[minHeap.top().second];
          visited.insert(minHeap.top().second);
          minHeap.pop();
          
          for(int i = 0; i < points.size();i++){
            vector<int>& p2 = points[i];
            if(visited.contains(i)) continue; //already found minimum path to this node, this will also make sure we don't look at current node as a possible neighbor.
            int w2 = abs(p2[0] - p1[0]) + abs(p2[1] - p1[1]); //weight from p1 to p2

            minHeap.push({w2,i});
          }
        }

        return sol;
    }
};