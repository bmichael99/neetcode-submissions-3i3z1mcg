class Solution {
public:
    int countSubstrings(string s) {
        int substrings = 0;

        for(int i = 0; i < s.length();i++){
            int L = i;
            int R = i;
            while(L >= 0 && R <= s.length()-1 && s[L] == s[R]){
                L--;
                R++;
                substrings++;
            }

            L = i;
            R = i+1;
            while(L >= 0 && R <= s.length()-1 && s[L] == s[R]){
                L--;
                R++;
                substrings++;
            }
        }
        return substrings;
    }
};