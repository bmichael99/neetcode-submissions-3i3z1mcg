class Solution {
public:
    string longestPalindrome(string s) {
        //we go through every character in the array O(n) and expand outwards and find the longest palindromic substring starting from that character as the center O(n), total time complexity: O(n^2)
        //The first described case is only for substrings of odd length where we have 1 character as the center, so we do this a second time with even substrings where two characters are at the center.
        int longest = 0;
        string sol = "";
        for(int i = 0; i < s.length();i++){
            int L = i;
            int R = i;
            
            while(L >= 0 && R <= s.size()-1 && s[L] == s[R]){
                L--;
                R++;
            }
            R--;
            L++;
            if(R-L+1 > longest){
                longest = max(longest,R-L+1);
                sol = s.substr(L,R-L+1);
            }
            

            L = i;
            R = i+1;
            while(L >= 0 && R <= s.size()-1 && s[L] == s[R]){
                L--;
                R++;
            }
            L++;
            R--;
            if(s[L] == s[R] && R-L+1 > longest){
                longest = max(longest,R-L+1);
                sol = s.substr(L,R-L+1);
            }
        }
        return sol;
    }
};