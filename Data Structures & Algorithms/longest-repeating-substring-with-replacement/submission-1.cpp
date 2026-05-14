class Solution {
public:
    int characterReplacement(string s, int k) {
        //brute force: O(n^3) generate all possible substrings and replace letters with highest frequency letter in substring. If valid substring (replacements are within k) then compare against a global largestSubstring variable.
        //optimal: variable size window problem, we grow the window as long as k >= 0, we decrease from k when we find a letter that's not the highest frequency letter. We update highest frequency letter while iterating through the string. Always making sure that we are within k replacements. If we run out of k, then we need to decrease the size of the window until we have at least 1 k.
        
      int L = 0;
      unordered_map<int,int> freq;
      // int highestFreq = s[0]; //letter with highest frequency
      int longestSubstring = 0;
      for(int R = 0; R < s.length(); R++){
        freq[s[R]]++;
        // if(freq[s[R]] > freq[highestFreq]){
        //   highestFreq = s[R];
        // }

        while((R-L+1 - findLargest(freq)) > k){ //R-L+1 - freq[highestFreq] is the number of replaced characters
          freq[s[L]]--;
          L++;
        }
        longestSubstring = max(longestSubstring,R-L+1);
      }
      return longestSubstring;
    }

    int findLargest(unordered_map<int,int>& freq){
      int largest = 0;
      for(auto& [key,val] : freq){
        largest = max(largest,val);
      }
      return largest;
    }
};