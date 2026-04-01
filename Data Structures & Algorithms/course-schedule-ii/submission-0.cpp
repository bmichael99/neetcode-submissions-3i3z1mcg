class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //we need to have a visited for the current path and a visited for topSort.
        //if we run into a visited for the current path then we ahve a cycle and return an empty array
        //use topsort to get the ordering of courses you should take to finish all courses.
        //topsort works by going "bottom up" on the graph, where we traverse to the end and then push to a "sorted" vector on our way back up the recursion tree, so we essentially go to the end of the graph and push in reverse order.
        //the end of the graph is either a topsort visited node or a node with no more neighbors.

        unordered_map<int,vector<int>> adjList;
        vector<int> topOrder;
        unordered_set<int> inPath;
        unordered_set<int> visited;

        for(vector<int>& prereq : prerequisites){
            adjList[prereq[1]].push_back(prereq[0]); //take b if you want to take a, b->a
        }

        for(int i = 0; i < numCourses;i++){
            if(!topSort(i,adjList,topOrder,inPath,visited)){
                return {};
            }
        }
        reverse(topOrder.begin(),topOrder.end());
        return topOrder;
    }

    bool topSort(int course, unordered_map<int,vector<int>>& adjList, vector<int>& topOrder, unordered_set<int>& inPath, unordered_set<int>& visited){
        if(inPath.contains(course)){
            return false;
        }
        if(visited.contains(course)){
            return true;
        }

        inPath.insert(course);
        for(int& neighbor: adjList[course]){
            if(!topSort(neighbor,adjList,topOrder,inPath,visited)){
                return false;
            }
        }
        //bottom up, starting from the end of the graph
        topOrder.push_back(course);
        visited.insert(course); //top sort has visited this need, mark as visited to avoid repeated work.
        inPath.erase(course);
        return true;
    }


};