class Solution {
public:
    int reverse(int x) {
        //add digits to output from right to left, and multiply output by 10 before adding the next digit, if multiplying by 10 would cause overflow, then return 0.
        //TC: O(n), SP: O(1)

        bool negative = x < 0;
        if(x == INT_MIN) return 0;
        x = abs(x);
        int output = 0;

        while(x > 0){
          if(output > INT_MAX/10) return 0; //check if multiplying by 10 would overflow
          output*=10; //prepare output for next digit, so that next digit can be added to singles place
          output += x%10; //add right digit to output
          x/=10; //remove right digit from input
        }
        return negative ? -1*output : output;
    }
};