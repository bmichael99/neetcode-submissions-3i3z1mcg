class Solution {
public:
    bool isHappy(int n) {
      int curr = n;
      int next = 0;
      unordered_set<int> visited;
      while(true){
        visited.insert(curr);
        while(curr != 0){
          int end = curr%10;
          curr /= 10;
          next += pow(end,2);
        }
        curr = next;
        next = 0;
        if(curr == 1) return true;
        if(visited.contains(curr)) return false;
      }
      return false;
    }
};