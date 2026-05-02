class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //we use a deque and always keep the largest number at the left side of the deque. We need to keep track of both the value and the index in nums within the deque to make sure we're maintaining the size of the window.
        //when we go to add a new number to the deque, if the new number is larger than the number on the right side, we pop it, and continue popping until the deque is empty or the right side number is larger.
        //This will create a **Monotonically Decreasing Queue**, where the numbers in the deque will always be strictly decreasing from left to right thanks to the rules we have set and maintain for it.

        deque<pair<int,int>> window; //{num,index}
        vector<int> sol;

        for(int i = 0; i < nums.size();i++){
            
            while(!window.empty() && window.back().first < nums[i]){
                window.pop_back();
            }
            window.push_back({nums[i],i});
            if(!window.empty() && i-window.front().second+1 > k){
                window.pop_front();
            }

            if(i >= k-1){
                sol.push_back(window.front().first);
            }
        }
        return sol;

        //brute force O(n*k), probably TLE
        // int L = 0;
        // vector<int> sol;
        // for(int R = k-1; R < nums.size();R++){
        //     int maxWindow = -10001;
        //     for(int i = L; i <= R;i++){
        //         maxWindow = max(maxWindow,nums[i]);
        //     }
        //     sol.push_back(maxWindow);
        //     L++;
        // }
        // return sol;
    }
};