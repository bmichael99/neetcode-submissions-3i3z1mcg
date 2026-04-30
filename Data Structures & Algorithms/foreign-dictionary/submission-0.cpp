class Solution {
public:
    string sol;
    string foreignDictionary(vector<string>& words) {
        //A string a is lexicographically smaller than a string b if in the first position where a and b differ, string a has a letter that appears earlier in the alien language than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the shorter string is the lexicographically smaller one.
        //the strings in words should be sorted in this way.
        //so if we have wrt, and wrf, case #1: if they are sorted lexicographically than that means that t is smaller than f. case #2: If min(a.length,b.length) characters do not differ, then the shorter string is lexicographically smaller.
        
        
        //build the graph, we need a directed, acyclical graph (DAG)
        //we need to compare each word with every other word. O(n^2)

        //the list of words is sorted from smallest to largest lexicographical order
        //
        //since we know the words input should already be sorted, we just need to compare a word if the word in front of it
        unordered_map<char,vector<char>> adjList; 
        unordered_set<char> letters;
        unordered_map<char,bool> visited; //if a node has been visited then it's in the map with a value of false, if it's in the current path it's in the visited map with a value of true. If current path doesn't have a cycle set all values of visited within the current path to false to mark them as visited.

        //we need to know every uniqueue letter in words, if these letters form a DAG, then we have a valid lexicographical order.
        for(string& word: words){
            for(char& c : word){
                letters.insert(c);
            }
        }

        for(int i = 0, j=i+1; j < words.size();i++,j++){
            int c = 0;
            //case #1
            while(c < words[i].length() && c < words[j].length()){
                if(words[i][c] == words[j][c]){
                    c++;
                    continue;
                }
                adjList[words[i][c]].push_back(words[j][c]);
                break;
            }
            //case #2
            if(c == min(words[i].length(), words[j].length()) && words[i].length() > words[j].length()){
                return "";
            }
        }

        for(auto& letter : letters){
            if(topSort(letter, adjList,visited)){
                return "";
            }
        }
        
        for(int i = 0; i < sol.size()/2;i++){
            swap(sol[i],sol[sol.size()-i-1]);
        }
        return sol;
    }

    bool topSort(int letter, unordered_map<char,vector<char>>& adjList, unordered_map<char,bool>& visited){
        if(visited.contains(letter) && visited[letter] == false){ 
            return false;
        }
        if(visited[letter] == true){
            return true;
        }

        visited[letter] = true;

        for(char& neighbor : adjList[letter]){
            if(topSort(neighbor,adjList,visited)){
                return true;
            }
        }

        visited[letter] = false;
        sol += letter;
        return false;
    }
};