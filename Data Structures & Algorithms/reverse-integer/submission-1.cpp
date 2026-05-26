class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if(x < 0) negative = true;
        if(x == INT_MIN) return 0;
        x = abs(x);

        int sol = 0;
        int i = 0;
        while(x > 0){
          if(sol > INT_MAX/10) return 0;
          sol *= 10;
          sol += x%10;
          x /= 10;
        }
        return negative == true ? -1 * sol : sol;
    }
};