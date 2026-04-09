class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //naive brute force: generate all possible subarrays and compute their products, keep largest product.
        //generate prefix products going both forwards and backwards and if we run into a 0 reset the product. then go through array and say that either left or right side can be max or by multiplying them together. To make things simple you could include the current index in the left prefix product.
        //[-4,2,3,4,5,0,4,2,1]
        //we actually iterate on this and do it a little better, instead of pre-calculating prefix and suffix products we can just run through prefix and suffix and calculate max product on the fly


        //kadanes algorithm is to add numbers until we reach a negative, when we reach a negative sum we reset the current sum and start over from the current index, since there's no benefit to continuing that subarray.
        //for product subarray we can still use kadanes algorithm but it's different, we need to track the currMin and currMax in the case where we have a large negative number and run into another negative number, will get a new max.
        int currMax = 1;
        int currMin = 1;
        int res = nums[0];
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == 0){
                currMax = 1;
                currMin = 1;
            }
            int temp = currMax;
            currMax = max(currMax*nums[i],max(nums[i],currMin*nums[i]));
            currMin = min(currMin*nums[i],min(nums[i],temp*nums[i]));

            res = max(currMax,res);
        }
        return max(currMax,res);;
      
    }
  


};






/* PREFIX AND SUFFIX

int n =  nums.size();
        int prefix = 0;
        int suffix = 0;
        int maxProduct = INT_MIN;
        for(int i = 0; i < n;i++){
          prefix = nums[i] * ((prefix == 0) ? 1 : prefix);
          suffix = nums[n-1-i] * ((suffix == 0) ? 1 : suffix);
          maxProduct = max(maxProduct, max(prefix,suffix));
        }
      return maxProduct;


*/


// //BRUTEFORCE
//         int maxProduct = INT_MIN;
//         int currProduct = 1;
//         for(int i = 0; i < nums.size();i++){
//           for(int j =[2,3,-2,4] i; j < nums.size();j++){
//             currProduct *= nums[j];
//             maxProduct = max(maxProduct,currProduct);
//           }
//           currProduct = 1;
//         }

//         return maxProduct;


