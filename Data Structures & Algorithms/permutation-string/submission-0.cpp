class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //do a fixed length window scan of s2 of size s1 to check if s2 has a permutation of s1.
        //how to check if it's a permutation: keep a frequency map of s1 and maintain an updating frequency map of the window in s2.
        //If the maps match then we know s2 contains a permutation of s1, O(n) time complexity
        if(s1 == s2) return true;

        if(s2.length() < s1.length()){
            return false;
        }

        vector<int> s1Freq(26,0);
        vector<int> s2Freq(26,0);

        for(char& c : s1){
            s1Freq[c - 'a']++;
        }

        for(int i = 0; i < s1.length()-1;i++){
            s2Freq[s2[i] - 'a']++;
        }

        for(int i = s1.length()-1;i < s2.length();i++){
            s2Freq[s2[i] - 'a']++;
            if(s1Freq == s2Freq){
                return true;
            }
            s2Freq[s2[i-s1.length()+1] - 'a']--;
        }
        

        return false;
    }
};