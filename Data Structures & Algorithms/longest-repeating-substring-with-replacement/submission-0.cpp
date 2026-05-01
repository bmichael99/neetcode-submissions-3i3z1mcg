class Solution {
public:
    int characterReplacement(string s, int k) {
      unordered_map<int,vector<int>> adjList;
      unordered_map<char,bool> visited;
      unordered_map<char,int> freq;
      int longestSubstring = 0;
      int largest = 0;
      
      //contain a map of the most frequently visited letters, we maintain a window of varying size, and a valid window is (window size) - mostFrequentLetter <= k, there can be at most k letters that are no the most frequent letter because change all the letters other than the most frequent to the most frequent letter.
      int L = 0;
      for(int R = 0; R < s.length();R++){
        freq[s[R]]++;
        largest = max(largest,freq[s[R]]);

        if((R-L+1) - largest > k){ //too many replaced characters, decrease window size until the window size is valid again.
          freq[s[L]]--;
          L++;
        } 

        longestSubstring = max(longestSubstring,R-L+1);
      }
      return longestSubstring;


    }

    // int findLargest(unordered_map<char,int>& freq){
    //   int largest = 0;
    //   for(auto [key,val] : freq){
    //     largest = max(largest,val);
    //   }
    //   return largest;
    // }
};