class UnionFind{
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> rank; //height
    UnionFind(int n){
        for(int i = 0; i < n;i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x){ //return root node and path compression

      while(x != parent[x]){
        parent[x] = parent[parent[x]];
        x = parent[x];
      }
        return x;
    }
    bool join(int n1, int n2){
        int p1 = find(n1);
        int p2 = find(n2);

        if(p1 == p2){ //parents are the same, so this would detect a cycle when you should only join each node once.
            return false;
        }

        if(rank[p1] > rank[p2]){
            parent[p2] = p1;
        } else if(rank[p2] > rank[p1]){
            parent[p1] = p2;
        } else {
            parent[p1] = p2;
            rank[p2]++;
        }

        return true;
    }
};

class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    UnionFind uf(n);
    
    for(vector<int>& edge: edges){
      uf.join(edge[0], edge[1]);
    }

    int components = 0;
    for(int i = 0; i < n;i++){
      if(uf.parent[i] == i){
        components++;
      }
    }
    return components;
  }
};