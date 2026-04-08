class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //start from the top of the stairs and work our way backwards.
        
        for(int i = cost.size()-3; i >= 0 ;i--){
            cost[i] = cost[i] + min(cost[i+1],cost[i+2]);
        }

        return min(cost[0],cost[1]);
    }
};