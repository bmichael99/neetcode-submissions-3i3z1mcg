class Solution {
public:
    int countSubstrings(string s) {
      //optimal: dp problem, starting from each index, expand outwards from both even and odd centers and check if the substring is a palindrome. Time Complexity: O(n^2)
      //naive brute force: Time Complexity: O(n^3) generate all substrings O(n^2) and check if each substring is a palindrome O(n)
      //Space complexity O(1)
      //In my initial implementation I didn't stop looping once s[L] != s[R], no good.

      int n = s.length();
      int L = 0;
      int R = 0;
      int countPalindromes = 0;

      for(int i = 0; i < n;i++){
        L = i;
        R = i;
        //odd center
        while(L >= 0 && R < n && s[L] == s[R]){
          countPalindromes++;
          L--;
          R++;
        }
        //even center
        L = i;
        R = i+1;
        while(L >= 0 && R < n && s[L] == s[R]){
          countPalindromes++;
          L--;
          R++;
        }
      }
      return countPalindromes;
    }
};