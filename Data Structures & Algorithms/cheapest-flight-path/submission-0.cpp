class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //use dijkstra's algorithm and we need to keep track of the number of stops used to reach the current point based on the current path, we also keep track of weight of that path. If we reach the destination and it's not within k stops then we have to keep running the algorithm and we allow for shorter paths to be overwritten if they have fewer stops, that way once we reach the destination again with a heigher weight but with fewer steps, we might be within k.

        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> minHeap; //<weight, [node, steps]>
        minHeap.push({0,{src,-1}}); //start with -1 stops instead of 0 because dst does not count as a stop 
        unordered_map<int,vector<pair<int,int>>> adjList;//adjList[src] = {dst,weight};
        vector<int> stops(n,INT_MAX);

        for(vector<int>& flight : flights){
          adjList[flight[0]].push_back({flight[1],flight[2]}); //adjList[src] = {dst,weight};
        }

        while(!minHeap.empty()){
          int w1 = minHeap.top().first;
          int n1 = minHeap.top().second[0];
          int k1 = minHeap.top().second[1];
          minHeap.pop();

          if(n1 == dst && k1 <= k){ //if we have reached the destination in at most k stops
            return w1; //return price to destination
          }
          if(k1 > stops[n1]) continue; //continue if we've already visited this node and this path has more stops than the previous path, that means that since we've already visited this node we have a higher weight, and we have higher stops. Waste of time continuing down this path.
          stops[n1] = k1;

          for(pair<int,int>& neighbor : adjList[n1]){
            int n2 = neighbor.first;
            int w2 = neighbor.second;
            int k2 = k1+1;

            if(k2 > k) continue;

            minHeap.push({w1+w2,{n2,k2}});
          }

        }


        return -1;
    }
};