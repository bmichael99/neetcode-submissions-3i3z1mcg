class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 0;
        char last = 'a';
        int j = 0;
        for(int i = 0; i < chars.size();i++){
          if(count == 0) {
              count++;
              last = chars[i];
              continue;
          }

          if(chars[i] == last){
            count++;
          } else {
            if(count == 1){
              chars[j] = last;
              j++;
            } else {
              chars[j] = last;
              j++;

              string count_string = to_string(count);
              for(char& c : count_string){
                chars[j] = c;
                j++;
              }
              
            }
            count = 1;
            last = chars[i];
          }
        }
        //to account for last character
        if(count == 1){
          chars[j] = last;
          j++;
        } else {
          chars[j] = last;
          j++;

          string count_string = to_string(count);
          for(char& c : count_string){
            chars[j] = c;
            j++;
          }
        }
      int n = chars.size();
      while(j < n){
        chars.pop_back();
        n = chars.size();
      }
      return chars.size();
    }
};