class UnionFind {
public:
  unordered_map<int,int> parent;
  unordered_map<int,int> rank;

  UnionFind(int n){
    for(int i = 0; i < n;i++){
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find(int x){
    int p = parent[x];
    while(p != parent[p]){ //search until we find the root of a tree, where p is the parent of itself.
      parent[p] = parent[parent[p]]; //set the parent of p to the grandparent of p
      p = parent[p]; 
    }
    return p;
  }

  bool join(int n1, int n2){
    int p1 = find(n1);
    int p2 = find(n2);

    if(p1 == p2){
      return false;
    }

    if(rank[p2] > rank[p1]){
      parent[p1] = p2;
    } else if(rank[p1] > rank[p2]){
      parent[p2] = p1;
    } else{
      parent[p2] = p1;
      rank[p1]++;
    }
    return true;
  }


};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    UnionFind uf(n);
    
    for(vector<int>& edge : edges){
      if(!uf.join(edge[0], edge[1])){
        return edge;
      }
    }
    return {};
  }
};