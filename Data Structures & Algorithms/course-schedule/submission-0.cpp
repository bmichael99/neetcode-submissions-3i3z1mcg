class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //[a,b] indicates a line from b -> a
        //If there's a cycle then we cannot take all courses
        //Graphs can be disconnected, so we need to explore all graphs for cycles.
        //we keep track of visited for the current path, if we run into another visited node on the current path then we can't finish.
        //make sure to backtrack visited so that we can clean up visited when we haven't found a cycle. There can be a case where we start
        //in the middle of the graph, we don't want to leave those nodes as visited because when we start from the earlier section we will see visited nodes and return
        //a false positive
        //TLE: To build upon what I previously mentioned, if we've already explored part of a graph, we can just delete that part of the graph so that we don't re-explore that part of the graph. This makes the algorithm much quicker.

        unordered_map<int,vector<int>> adjList;
        unordered_set<int> visited;

        for(vector<int>& prereq : prerequisites){
            adjList[prereq[1]].push_back(prereq[0]);
        }

        for(int i = 0; i < numCourses;i++){
            if(!DFS(i,adjList,visited)){
                return false;
            }
        }
        
        return true;
    }

    bool DFS(int course, unordered_map<int,vector<int>>& adjList, unordered_set<int>& visited){
        if(visited.contains(course)){
            return false;
        }

        visited.insert(course);
        for(int& neighbor : adjList[course]){
            if(!DFS(neighbor,adjList,visited)){
                return false;
            }
        }
        visited.erase(course);
        adjList[course] = {}; //delete explored portions of graphs that don't return false (no cycle found), this speeds up future DFS so we don't have repeated work.

        return true;
    }
};