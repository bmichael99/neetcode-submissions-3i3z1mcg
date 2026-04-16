class Solution {
public:
    int jump(vector<int>& nums) {
        //O(n^2): from the current step see if we can reach the last index in the array, if we can't we want to jump to the step that will take us the farthest within our range. Keep in mind that numbers closer to the current index are farther away from the last index, so the largest number is not always best but instead the number that will take us the farthest relative to its position is the best.

        //O(n) don't rescan the same parts of the array for the farthest jump, we've calculated the jump distances of these numbers once and they do not need to be scanned again.
        
        int n = nums.size();
        int jumpCount = 0;
        int i = 0;
        int j = 0;
        if(n==1) return 0;
        while(i < n){
            if(i + nums[i] >= n-1){
                return jumpCount+1;
            }
            //find which number to jump to
            int largest = -1;
            int largestIndex = -1;
            while((j <= i+nums[i]) && (j < n)){
                if(nums[j] + j-i-1 > largest){
                    largest = nums[j] + j-i-1;
                    largestIndex = j;
                }
                j++;
            }
            i = largestIndex;
            jumpCount++;
        }
        return jumpCount;
    }
};