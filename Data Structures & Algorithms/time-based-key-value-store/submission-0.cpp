class TimeMap {
public:
  //time stamps are given in strictly increasing order, so binary search can be used when searching for a timestamp. We want to return a time that's <= timestamp
    unordered_map<string,vector<pair<string,int>>> times; //key -> val,timestamp
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        times[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
      if(!times.contains(key)) return "";
      auto& curr = times[key];
      int L = 0;
      int R = curr.size()-1;
      string sol = "";
      while(L <= R){
        int M = (L+R)/2;

        if(curr[M].second > timestamp){
          R = M-1;
        } else if(curr[M].second < timestamp){
          sol = curr[M].first;
          L = M+1;
        } else {
          return curr[M].first;
        }
      }
      return sol;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */