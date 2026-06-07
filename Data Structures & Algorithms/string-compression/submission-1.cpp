class Solution {
public:
    int compress(vector<char>& chars) {
        char last = chars[0];
        int count = 0;
        int j = 0; //current index in chars

        for(char& c: chars){
          if(c == last){
            count++;
          } else {
            chars[j] = last;
            j++;
            if(count > 1){
              string count_string = to_string(count);
              for(char& cc : count_string){
                chars[j] = cc;
                j++;
              }
            }
            count = 1;
            last = c;
          }
        }

        chars[j] = last;
        j++;
        if(count > 1){
          string count_string = to_string(count);
          for(char& cc : count_string){
            chars[j] = cc;
            j++;
          }
        }


        return j;
    }
};