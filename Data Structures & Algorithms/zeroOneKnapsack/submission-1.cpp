class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        //top-down memoized O(n*capacity)
        vector<vector<int>> cache(profit.size(), vector<int>(capacity+1,-1));
        return backTracking(0,profit,weight,capacity,cache);
    }

    int backTracking(int i, vector<int>& profit, vector<int>& weight, int capacity, vector<vector<int>>& cache){
        if(i >= profit.size()){
            return 0;
        }
        if(cache[i][capacity] != -1){
            return cache[i][capacity];
        }

        //skip num 
        int maxProfit = backTracking(i+1,profit,weight,capacity,cache);


        //choose num
        if(capacity-weight[i] >= 0){
            int currProfit = profit[i] + backTracking(i+1,profit,weight,capacity-weight[i],cache);
            maxProfit = max(currProfit,maxProfit);
        }

        cache[i][capacity] = maxProfit;
        return cache[i][capacity];
    }
};
