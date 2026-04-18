class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        //loop through triplets and merge any triplet that has a value equal to target as long as the rest of the values are <= target as well.
        vector<int> sol = {0,0,0}; //1 <= ai, bi, ci, x, y, z <= 1000
        //return if sol == target, we attempt to get sol to become target by merging triplets

        for(vector<int>& triplet : triplets){
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                sol = {max(sol[0],triplet[0]), max(sol[1],triplet[1]), max(sol[2],triplet[2])};
            }
        }
        return sol == target;
    }
};