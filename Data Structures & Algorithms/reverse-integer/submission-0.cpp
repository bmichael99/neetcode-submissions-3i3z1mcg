class Solution {
public:
    int reverse(int x) {
        //to reverse a number we can use %10 to get least significant numbers, /10 to remove least significant numbers.
        bool negative = x < 0;
        if(x == INT_MIN || x == INT_MAX) return 0;
        x = abs(x);
        
        int sol = 0;

        while(x > 0){
          if(sol > INT_MAX/10) return 0;
          sol *= 10;
          sol += x%10;
          x/=10;
        }

        if(negative) sol = -sol;

        return sol;
    }
};