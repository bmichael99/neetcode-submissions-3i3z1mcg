class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //count frequencies for each task and add them to a minheap. We always want to use the task that's of highest frequency. Have a queue that holds tasks that have been recently used, use a timestamp to know when it was last used. After cooldown of n we can pop from queue, keep track of current time.
        //TC: O(nlog(26)) = O(n), SC:O(26) = O(1)
        //priority queue operations have a time complexity of logn but since we know that there can only be 26 tasks we know it's a constant.

        int time = 0;
        unordered_map<char,int> freq;
        queue<pair<char,pair<int,int>>> cooldown; //task -> time_stamp when used, freq remaining
        priority_queue<pair<int,char>> minHeap; //freq, task


        for(char& task : tasks){
          freq[task]++;
        }

        for(auto& [key,val] : freq){
          minHeap.push({val,key});
        }

        while(!minHeap.empty() || !cooldown.empty()){
          //if we use a task on time 0 and n=2, we can use that task again on time 3
          while(!cooldown.empty() && (time - cooldown.front().second.first) > n){ 
            auto front = cooldown.front();
            minHeap.push({front.second.second,front.first}); //push freq remaining and task to minHeap
            cooldown.pop();
          }

          if(!minHeap.empty()){
            int top_count = minHeap.top().first;
            char top_task = minHeap.top().second;
            top_count -= 1;

            if(top_count > 0){
              cooldown.push({top_task,{time,top_count}});
            }
            minHeap.pop();
          }
          time++;
        }
      return time;
    }
};