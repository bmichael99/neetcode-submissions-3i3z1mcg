class Solution {
public:
    int components;
    bool validTree(int n, vector<vector<int>>& edges) {
        //a tree is connected and acyclic.
        //union find does both of these, detecting cycles and counting components, but I won't use that here.
        //for cycle just keep track of current path with a visited/currPath set.
        //for connected graph, if we don't run into a global visited node, we increase the count of graphs. If we have more than 1 graph, return false.
        
        unordered_set<int> visited;
        unordered_set<int> currPath;
        unordered_map<int,vector<int>> adjList;

        for(vector<int>& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        components = 0;
        for(int i = 0; i < n; i++){
            components++;
            if(!DFS(i,-1,adjList,visited,currPath)){
                return false;
            }
            if(components > 1){ //disconnected graph
                return false;
            }
        }
        return true;
    }

    //prev keeps track of previous node. since we know there's no repeated edges we don't have to worry about a case where two repeated edges form a cycle.

    bool DFS(int i, int prev, unordered_map<int,vector<int>>& adjList, unordered_set<int>& visited, unordered_set<int>& currPath){
        if(currPath.contains(i)){
            return false;
        }
        if(visited.contains(i)){
            components--; //part of a previous graph, decrease component count by 1 (we increased by 1 before calling DFS in the case where we don't find a previously visited graph)
            return true;
        }

        currPath.insert(i);
        for(int& neighbor: adjList[i]){
            if(neighbor != prev) //do not cycle back to previous node (undirected graph)
                if(!DFS(neighbor,i,adjList,visited,currPath)){
                    return false;
                }
        }

        visited.insert(i);
        currPath.erase(i);
        return true;
    }
};