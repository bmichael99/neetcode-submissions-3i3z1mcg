class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //gas stations are circular, gas[i] = amount of gas
        //gas tank is unlimited and costs cost[i] to travel from ith station to its (i+1)th station.
        //start with empty tank at any gas station
        //return starting gas stations' index if you can travel around the circuit once in a clockwise direciton, otherwise return -1 if no path exists.
        //If there a solution, it is garunteed to be uniqueue

        //naive bruteforce solution: start from each gas station and try to go through all the stations, if you can return the index otherwise return -1.
            //time complexity:O(n^2)
        
        //non-naive:
        //you can only start from a gas station that provides enough gas to drive to the next gas station, so gas >= cost.
        //sum of gas must be >= sum of cost
        //if we go below 0 gas then we just start over at the next station until we find the valid loop, we go max 2n laps

        int i = 0;
        int j = 0; //count successful gas trips
        int n = gas.size(); //gas.length == cost.length
        int station = 0;
        int tank = 0;

        while(2*n-i >= n-j && i < n*2){//while the stations remaining is >= the distance from j to n, this early exit speeds up the algorithm by quite a bit.
            station = i%n; //acounts for going in a circle
            tank += gas[station];
            tank -= cost[station];
            if(tank < 0){
                tank = 0;
                j = 0;
            } else{
                j++;
                if(j == n){
                    return (i-j+1)%n;
                }
            }
            i++;
        }
        return -1;
    }
};