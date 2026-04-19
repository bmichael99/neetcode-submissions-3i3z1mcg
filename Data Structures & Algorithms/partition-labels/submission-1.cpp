class Solution {
public:
    vector<int> partitionLabels(string s) {
        //generate sub-arrays where each letter is only in one part.
        //can do this greedy by having a count of each letter and as soon as one letter reaches a frequency of 0 in the current sub-array then you can end the current sub-string. However, you also need to keep a stack that'll contain all the current letters in the sub-string, the stack needs to be empty and all frequency of 0 in order to partition the smallest sub-string.
        //remove letters from set when freq becomes 0, if set is empty then we can reset partition and add partition to sol. If there's still characters in the string then push the next letter and start again.

        unordered_set<int> lettersInString;
        unordered_map<char,int> freq;
        int partition = 0; //we don't need to keep track of the actual partition but instead the size of the current partition.
        vector<int> sol; //return the sizes of each partition starting from index 0

        for(char& c : s){
            freq[c]++;
        }
        for(int i = 0; i < s.length(); i++){
            freq[s[i]]--;
            partition++;
            lettersInString.insert(s[i]);
            if(freq[s[i]] == 0){
                lettersInString.erase(s[i]);
            }
            if(lettersInString.empty()){
                sol.push_back(partition);
                partition = 0;
            }
        }

        return sol;
    }
};