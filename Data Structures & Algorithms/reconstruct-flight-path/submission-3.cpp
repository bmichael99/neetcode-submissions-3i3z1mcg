class Solution {
public:
    unordered_map<string,vector<string>> adjList;
    vector<string> path;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //Hierholzer's Algorithm (Recursion)
        //An Eulerian path (or Euler path) is a trail in a finite graph that visits every edge exactly once, allowing for multiple visits to vertices. 

// Hierholzer's Algorithm builds such a path by:
//     always taking an available edge,
//     going as deep as possible,
//     and adding airports to the answer only when no outgoing edges remain.

// To ensure the lexicographically smallest itinerary:
//     we sort tickets,
//     and always pick the smallest destination first.

// The key idea:
//     Build the path in reverse while backtracking. 

        sort(tickets.rbegin(),tickets.rend());
        

        for(vector<string>& ticket: tickets){
            adjList[ticket[0]].push_back(ticket[1]);
        }

        DFS("JFK");
        reverse(path.begin(),path.end());
        return path;
    }

    void DFS(const string& airport){

        while(!adjList[airport].empty()){
            string dst = adjList[airport].back();
            adjList[airport].pop_back();
            DFS(dst);
        }

        path.push_back(airport);
    }
};