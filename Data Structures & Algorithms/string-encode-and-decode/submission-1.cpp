class Solution {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        //define a delimiter, in this case we will say /:, if the original string contains a / we make it a //, when decoding if we see a / we check if it's a delimiter by seeing if the next character is : or /
        string newString = "";
        for(string& str : strs){
          for(char& c : str){
            if(c == '/'){
              newString += "//";
              continue;
            }
            newString.push_back(c);
          }
          newString += "/:";
        }
        return newString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
      vector<string> strings;
      string curr = "";
        for(int i = 0; i < s.length();i++){
          if(s[i] == '/' && s[i+1] == '/'){
            curr += s[i];
            i++;
          } else if(s[i] == '/' && s[i+1] == ':'){
            strings.push_back(curr);
            curr = "";
            i++;
          } else {
            curr += s[i];
          }
        }
        return strings;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));