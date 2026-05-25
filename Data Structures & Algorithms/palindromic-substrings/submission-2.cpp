class Solution {
public:
  int countSubstrings(string s) {
    //DP problem where we find all substrings that are palindromes
    //Brute force: generate all possible substrings and check if each substring is a palindrome. O(n^3)
    //Optimal: O(n^2), iterate through list where each index will be the center of a palindrome. Grow substring outwards and check if each substring is a palindrome. need to do both odd and even centers.
    int n = s.length();
    int count = 0;
    for(int i = 0; i < n;i++){
      int L = i;
      int R = i;

      while(L >= 0 && R <= n-1 && s[L] == s[R]){
        count++;
        L--;
        R++;
      }

      L = i;
      R = i+1;

      while(L >= 0 && R <= n-1 && s[L] == s[R]){
        count++;
        L--;
        R++;
      }
    }
    return count;
  }
};