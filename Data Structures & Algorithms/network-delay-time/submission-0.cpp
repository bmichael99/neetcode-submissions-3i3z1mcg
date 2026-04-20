class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,int> shortestPath;

        //<weight,node>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap; 

        //sourceNode : vector<destNode,weight> (neighbors)
        unordered_map<int,vector<pair<int,int>>> adjList; 

        for(vector<int>& time : times){
          //time[0] = source node
          //time[1] = target node
          //time[2] = time for signal to travel from source to target
          adjList[time[0]].push_back({time[1],time[2]});
        }

        minHeap.push({0,k});

        while(!minHeap.empty()){
          pair<int,int> currNode = minHeap.top();
          minHeap.pop();

          if(!shortestPath.contains(currNode.second)){
            shortestPath[currNode.second] = currNode.first;
          } else {
            continue; //don't do repeated work, if we've already visited this node then continue to next shortest path.
          }

          //if we've explored all paths now, return length to this node, since it's the last node to be reached it's the max time to reach all nodes. 
          if(shortestPath.size() == n) return currNode.first;

          for(pair<int,int>& neighbor : adjList[currNode.second]){
            //push weight to current node + weight to next node for total path weight.
            minHeap.push({currNode.first + neighbor.second,neighbor.first});
          }

          //remove node once we've pushed all its neighbors, stops infinite loops and repeated work in case of loops
          adjList.erase(currNode.second);
        }
        return -1;
    }
};