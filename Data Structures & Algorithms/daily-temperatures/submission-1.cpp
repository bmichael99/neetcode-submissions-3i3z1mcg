class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //brute froce is O(n^2) starting from each index and searching for hotter temperature
        //decreasing monotonic stack, push temperature and index. If a smaller temperature is found than the top of the stack, pop until larger temperature. Top of the stack will always contain the smallest temperature, which is what makes monotonic stacks work well here.
        //TC: O(n) SC: O(n) worst case where temperature input would be strictly decreasing as well
        stack<int> st;
        int n = temperatures.size();
        vector<int> sol(n);
        for(int i = 0; i < n; i++){
          while(!st.empty() && temperatures[st.top()] < temperatures[i]){
            sol[st.top()] = i - st.top();
            st.pop();
          }
          st.push(i);
        }
      return sol;
    }
};