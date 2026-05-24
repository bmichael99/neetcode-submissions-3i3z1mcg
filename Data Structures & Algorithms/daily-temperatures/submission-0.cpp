class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //brute force: starting from each temperature, loop through the rest of the array and look for the first warmer temperature. O(n^2)
        //optimal: stack problem. Always remove numbers from stack that are smaller and push difference between indexes to answer array.
        //push temperature and index to stack, if current temperature is larger than number in stack, we can update index in solution that matches the index of the colder temperature.

        stack<pair<int,int>> temps;
        int n = temperatures.size();
        vector<int> answer(n);

        for(int i = 0; i < temperatures.size();i++){
          while(!temps.empty() && temps.top().first < temperatures[i]){
            answer[temps.top().second] = i - temps.top().second; //difference in days between now and the day of this temperature. We are at a warmer day than the colder day in the stack.
            temps.pop();
          }
          temps.push({temperatures[i],i});
        }

        while(!temps.empty()){
          answer[temps.top().second] = 0;
          temps.pop();
        }

        return answer;
    }
};