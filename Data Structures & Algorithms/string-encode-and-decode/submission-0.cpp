class Solution {
public:
  //seperate words with a seperator like /:, first check the string for any / and replace them with //, that way when we find a / we can check if it's a // or a /: by checking the character after the /

  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string encodedString = "";

    for(string& str : strs){
      for(char& c : str){
        if(c == '/'){
          encodedString += "//";
          continue;
        }
        encodedString += c;
      }
      encodedString += "/:";
    }
    return encodedString;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> decodedStrings;
    string curr = "";
    int i = 0;
    while(i < s.length()){
      if(s[i] == '/' && s[i+1] == '/'){
        curr.push_back('/');
        i++;
      } else if(s[i] == '/' && s[i+1] == ':'){
        decodedStrings.push_back(curr);
        curr = "";
        i++;
      } else {
        curr += s[i];
      }
      i++;
    }
    return decodedStrings;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));