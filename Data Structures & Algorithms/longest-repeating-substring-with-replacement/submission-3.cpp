class Solution {
public:
    int characterReplacement(string s, int k) {
        //dynamic sized window problem. based on current window size you can replace k letters that aren't the letter of the highest frequency.
        //TC: with findLargest, O(26n) = O(n)
        //SC: O(26) = O(1)

        int L = 0;
        int largest_substring = 0;
        vector<int> freq(26,0);
        int largest = 0; //optimization: use largest instead of a findLargest function to remove multiplying by O(26)
        //since we know a new largest substring can't be found without a larger largest, we don't have to worry about having a stale largest integer.
        //TC: O(n)
        //SC: O(26) = O(1)

        for(int R = 0; R < s.length();R++){
          freq[s[R] - 'A']++;
          largest = max(largest, freq[s[R] - 'A']);
          while((R-L+1) - largest > k){
            freq[s[L] - 'A']--;
            L++;
          }
          largest_substring = max(largest_substring,R-L+1);
        }
        return largest_substring;
    }

    // int findLargest(vector<int>& freq){
      
    //   int largest = 0;
    //   for(int& num : freq){
    //     largest = max(largest,num);
    //   }

    //   return largest;
    // }
};