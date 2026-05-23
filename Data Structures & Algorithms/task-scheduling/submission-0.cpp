class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //keep track of current time and have a map where we keep track of number of tasks and the last time we used that task. We should always try to use tasks that have the most of a certain task. use up to n tasks before going back to the most used task. What we could do is keep a maxHeap to keep track of the currently highest count task, and also keep a queue that'll keep track of the task and the last time it was used. When we pop from maxHeap we push to the queue, and always check if the queue is ready to be used again, if it is we add it back to the maxHeap.

        priority_queue<pair<int,char>> maxHeap; //task count, task
        queue<pair<char,pair<int,int>>> cooldown; //task, task count, time stamp of last used

        unordered_map<char,int> freq;
        //count number of each task
        for(char& task : tasks){
          freq[task]++;
        }
        //push count and tasks to maxHeap
        for(auto& [key,val] : freq){
          maxHeap.push({val,key});
        }
        int time = 0;
        while(!maxHeap.empty() || !cooldown.empty()){
          while(!cooldown.empty() && cooldown.front().second.second + n + 1 == time){
            int task_count = cooldown.front().second.first;
            char task = cooldown.front().first;
            maxHeap.push({task_count,task});
            cooldown.pop();
          }
          if(!maxHeap.empty()){
            int task_count = maxHeap.top().first;
            char task = maxHeap.top().second;
            if(task_count > 1){
              cooldown.push({task, {task_count-1,time}});
            }
            maxHeap.pop();
          }

          time++;
        }
        return time;
    }
};