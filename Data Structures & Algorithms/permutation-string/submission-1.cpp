class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      //fixed size window problem
      //count frequency of letters as you progress through windows
      //subtract frequency of L and increase frequency of R
      if(s1.length() > s2.length()) return false;
      int s1_length = s1.length();
      int s2_length = s2.length();
      vector<int> s1Freq(26,0);
      vector<int> s2Freq(26,0);

      for(int i = 0; i < s1_length;i++){
        s1Freq[s1[i] - 'a']++;
        s2Freq[s2[i] - 'a']++;
      }
      if(s1Freq == s2Freq) return true;

      for(int i = s1_length; i < s2_length;i++){
        s2Freq[s2[i-s1_length] - 'a']--;
        s2Freq[s2[i] - 'a']++;

        if(s1Freq == s2Freq) return true;
      }
      return false;
    }
};