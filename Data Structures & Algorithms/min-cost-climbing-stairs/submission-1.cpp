class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      //botom up DP, O(n), at each step we account for the cost of the current step and then we can either travel 1 or two steps, we want to take the path with the smallest cost.
      int n = cost.size();
      vector<int> dp(n+1,0);
      dp[n] = 0;
      dp[n-1] = cost[n-1];
      
      for(int i = n-2; i >= 0; i--){
        dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
      }
      //can start from index 0 or index 1
      return min(dp[0],dp[1]);
    }


  //memoization O(n)
    // int minCostClimbingStairs(vector<int>& cost) {
      
    //   vector<int> cache(cost.size(),-1);
    //   return min(findCost(0,cost,cache),findCost(1,cost,cache));
    // }

    // int findCost(int i, vector<int>& cost, vector<int>& cache){
    //   if(i >= cost.size()){
    //     return 0;
    //   }
    //   if(cache[i] != -1){
    //     return cache[i];
    //   }

    //   cache[i] = cost[i] + min(findCost(i+1,cost,cache),findCost(i+2,cost,cache));
    //   return cache[i];
    // }

//bottom up recursion, doing the calculation on the way back up from the leaves. This is what's needed for memoization because you need an answer to cache.
    // int minCostClimbingStairs(vector<int>& cost) {
    //     return min(findCost(0,cost),findCost(1,cost));
    // }

    // int findCost(int i, vector<int>& cost){
    //   if(i >= cost.size()){
    //     return 0;
    //   }

    //   int minCost = cost[i] + min(findCost(i+1,cost),findCost(i+2,cost));
    //   return minCost;
    // }

//top down recursion, doing the calculation at each level while going down the recursion tree
// int minCost = INT_MAX;
//     int minCostClimbingStairs(vector<int>& cost) {
//         findCost(0,0,cost);
//         int test = minCost;
//         findCost(1,0,cost);
//         return min(minCost,test);
//     }

//     void findCost(int i, int currCost, vector<int>& cost){
//       if(i >= cost.size()){
//         if(i == cost.size()){
//           minCost = min(minCost,currCost);
//         }
//         return;
//       }

//       findCost(i+1,currCost+cost[i],cost);
//       findCost(i+2,currCost+cost[i],cost);
//     }
};