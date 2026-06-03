class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //brute force: generate all subarrays and calculate the largest product subarray
        //optimal 1: prefix/suffix product, generate arrays of products starting from left and right side, iterate through indexes and test not included each index and combining prefix and suffix. If we encounter a 0 we start over at 1
        //optimal 2: keep track of min and max, if we encounter a 0 we start over at 1.
        //TC: O(n)
        //SC: O(1)

        int min_num = 1;
        int max_num = 1;
        int largest_product = nums[0];

        for(int& num : nums){
          if(num == 0){
            min_num = 1;
            max_num = 1;
          }

          int temp = max_num;
          max_num = max(num,max(min_num*num,max_num*num));
          min_num = min(num,min(min_num*num,temp*num));
          largest_product = max(max_num,largest_product);
        }
        return largest_product;
    }
};