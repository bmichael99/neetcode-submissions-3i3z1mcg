class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int> freq;
      vector<int> sol;

      for(int& num : nums){
        freq[num]++;
      }
      priority_queue<pair<int,int>> maxHeap;
      for(auto& [key,val] : freq){
        maxHeap.push({val,key});
      }

      while(k > 0){
        sol.push_back(maxHeap.top().second);
        maxHeap.pop();
        k--;
      }
      return sol;
    }
};