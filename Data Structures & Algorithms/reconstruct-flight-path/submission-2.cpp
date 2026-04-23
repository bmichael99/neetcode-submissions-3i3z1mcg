class Solution {
public:
unordered_map<string, unordered_map<int,bool>> visited;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //A valid itinerary will take you to all nodes.
        //We say there can be more than one valid itinerary, meaning we're not necessarily given n-1 edges, where n is the number of nodes. A valid itinerary will be n-1 edges.
        //If there's more than one itinerary than we want the itinerary that's in smallest lexical order. We can probably think of lexical order as the weight of the node, if that thought processes is needed.
        //It's almost like building a minimum spanning tree but we're allowed to have loops, we just can't use the same edge twice, so we could backtrack to explore all possibilities
        //we can create a weight with lexical ordering by multiplying each place in the string by a factor of 10 based on its order, so index 0 will be multiplied by 10^3 since the first character holds the most weight, 1 will be 10^2 and so on.
        //explore the path with the lowest weight first.

        int n = tickets.size();
        sort(tickets.begin(),tickets.end()); //neighbors will be pushed in lexical order
        unordered_map<string,vector<string>> adjList; //adjList[src] = sorted neighbors by lexical order, explore lowest lexical orders first, we have a valid itinerary if we used all the tickets.
        for(vector<string>& ticket: tickets){
          adjList[ticket[0]].push_back(ticket[1]);
        }
        vector<string> path; //sol

        DFS(n,"JFK", adjList,path);

        return path;

    }

    
    bool DFS(int& n, string airport, unordered_map<string,vector<string>>& adjList,  vector<string>& path){
      path.push_back(airport);

      //explore smallest lexical order first, first path found will be valid since we sort in order.
      if(path.size() == n+1){ //itinerary built. n-1 edges for n nodes, so k edges(tickets) will have k+1 nodes
        return true;
      }


      for(int i = 0; i < adjList[airport].size();i++){
        string& neighbor = adjList[airport][i];

        if(visited[airport][i] == true) continue;
        visited[airport][i] = true;
        if(DFS(n,neighbor,adjList,path)){
          return true; //early exit if we find valid itinerary
        }
        visited[airport][i] = false; //backtrack, allow this neighbor to be visited again
      }
      path.pop_back();
      return false;//dead end, wasn't able to finish the itinerary
    }
};