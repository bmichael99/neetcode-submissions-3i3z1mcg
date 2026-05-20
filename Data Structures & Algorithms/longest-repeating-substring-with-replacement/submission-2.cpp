class Solution {
public:
    int characterReplacement(string s, int k) {
        //brute force: change 2 letters a time to each letter in the alphabet, every time 2 characters are changed check for a new longest substring.
        //TC: O(26*n^2) SC: O(1)
        //optimal: variable size window problem, keep track of most frequent letter, and check all other letters within the window to most frequent. If there's more than k changes we have to stop and shrink window until there's k again.
        //checking frequency: TC:O(26n) SC: O(26)
        //using largestFreq var: TC: O(n) SC: O(26)

        vector<int> freq(26,0);
        int largestFreq = 0;
        int L = 0;
        int longestSubstring = 0;
        for(int R = 0 ; R < s.length(); R++){
          freq[s[R] - 'A']++;
          largestFreq = max(largestFreq, freq[s[R] - 'A']);
          while((R-L+1) - largestFreq > k){ //too many replacements, replacements is greater than k
            freq[s[L] - 'A']--;
            L++;
          }
          longestSubstring = max(longestSubstring,R-L+1);
        }
      return longestSubstring;
    }

    // int largestFreq(vector<int>& freq){
    //   int largest = 0;
    //   for(auto& count : freq){
    //     largest = max(largest,count);
    //   }
    //   return largest;
    // }
};