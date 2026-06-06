class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      //count frequencies and compare. fixed sliding window. tc O(n) sc O(n)

      if(s1.length() > s2.length()) return false;

      vector<int> freqS1 (26,0);
      vector<int> freqS2 (26,0);

      for(int i = 0 ; i < s1.length();i++){
        freqS1[s1[i] - 'a']++;
        freqS2[s2[i] - 'a']++;
      }
      if(freqS1 == freqS2) return true;
     int L = 0;

      for(int i = s1.length(); i < s2.length(); i++){
        freqS2[s2[i] - 'a']++;
        freqS2[s2[L] - 'a']--;
        L++;

        if(freqS1 == freqS2) return true;
      }
      return false;

    }
};