class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // If a task is used it gets added to a queue with a timestamp attached
        // Keep a maxHeap with the frequency of tasks so that we always use the highest frequency task
        // TC: O(nlog(26)) = O(n), SC: O(26) = O(1)
        priority_queue<pair<int,char>> maxHeap; //count, task
        queue<pair<int,pair<int,char>>> coolDown; //cooldown, <count,task>

        unordered_map<char,int> freq;
        for(char& task : tasks){
          freq[task]++;
        }

        for(auto& [key,val] : freq){
          //add frequency count and task to maxHeap
          maxHeap.push({val,key});
        }
        int time = 0;
        while(!maxHeap.empty() || !coolDown.empty()){
          if(!coolDown.empty() && (time-coolDown.front().first) > n){
            maxHeap.push({coolDown.front().second.first,coolDown.front().second.second});
            coolDown.pop();
          }
          if(!maxHeap.empty()){
            if(maxHeap.top().first > 1)
              coolDown.push({time,{maxHeap.top().first-1,maxHeap.top().second}});
            maxHeap.pop();
          }
          time++;
        }
        return time;
    }
};