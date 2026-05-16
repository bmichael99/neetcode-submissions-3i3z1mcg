class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //decreasing monotonic stack problem, the number on the left is the largest
    deque<pair<int,int>> mono; //keep track of number and index
    vector<int> sol;
    for(int i = 0; i < k; i++){
      while(!mono.empty() && mono.front().first < nums[i]){
        mono.pop_front();
      }
      mono.push_front({nums[i],i});
    }

    for(int i = k; i < nums.size();i++){
      sol.push_back(mono.back().first);
      if((i-mono.back().second+1) > k){
        mono.pop_back();
      }

      while(!mono.empty() && mono.front().first < nums[i]){
        mono.pop_front();
      }
      mono.push_front({nums[i],i});
    }

    sol.push_back(mono.back().first);
    return sol;
  }
};