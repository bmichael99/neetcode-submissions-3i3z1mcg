class trieNode{
public:
    unordered_map<int,trieNode*> children;
    bool word = false;
};

class trie{
public:
    trieNode* root;
    trie(){
        root = new trieNode();
    }

    void addword(string word){
        trieNode* curr = root;

        for(char letter : word){
            if(curr->children.count(letter) == 0){
                curr->children[letter] = new trieNode();
            }
            curr = curr->children[letter];
        }
        curr->word = true;
    }

    bool search(string word){
        trieNode* curr = root;

        for(char letter : word){
            if(curr->children.count(letter) == 0){
                return false;
            }
            curr = curr->children[letter];
        }
        return curr->word;
    }

    bool prefix(string word){
        trieNode* curr = root;
        for(char letter : word){
            if(curr->children.count(letter) == 0){
                return false;
            }
            curr = curr->children[letter];
        }
        return true;
    }

};

class Solution {
public:
    trie myTrie;
    int rows = 0;
    int cols = 0;
    vector<string> answer;
    unordered_set<string> found;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = board[0].size();

        for(string word: words){
            myTrie.addword(word);
        }

        string currWord;

        for(int i = 0; i < rows;i++){
            for(int j = 0; j < cols;j++){
                string letter;
                letter = board[i][j];
                if(myTrie.root->children.count(board[i][j]) != 0){
                    backTracking(currWord,i,j,board,myTrie.root);
                }
            }
        }
    
        

        return answer;
    }

    void backTracking(string& currWord, int r, int c,vector<vector<char>>& board,trieNode* node){
        if(r < 0 || c < 0 || r == rows || c == cols || board[r][c] == '#'){
            return;
        }

        
        if(node->children.count(board[r][c]) == 0){
            return;
        }

        node = node->children[board[r][c]];
        currWord += board[r][c];
        char temp = board[r][c];

        if(node->word && found.count(currWord) == 0){
            answer.push_back(currWord);
            found.insert(currWord);
        }

        board[r][c] = '#';

        backTracking(currWord,r+1,c,board,node);
        backTracking(currWord,r-1,c,board,node);
        backTracking(currWord,r,c+1,board,node);
        backTracking(currWord,r,c-1,board,node);


        currWord.pop_back();
        board[r][c] = temp;

    }
};