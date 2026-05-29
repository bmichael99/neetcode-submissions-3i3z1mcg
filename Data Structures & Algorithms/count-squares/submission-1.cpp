class CountSquares {
public:
  //algorithm:
  //add: push all points to a hash map containing points and the frequency of that count.
  //count: check if a point exists that's diagonal to the current point. If there is check if the remaining two points exist by doing basic geometry
  //TC: O(n) where n is the number of points
  //SC: O(n) where n is the number of points

    unordered_map<int,unordered_map<int,int>> points;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
      points[point[0]][point[1]]++;        
    }
    
    int count(vector<int> point) {
      int x1 = point[0];
      int y1 = point[1]; 
      int squares = 0;
        for(auto& [x2,val] : points){
          for(auto& [y2,count] : val){
            if(x1 == x2 || y1 == y2) continue; //continue if point can't be diagonal and might be the same point
            if(abs(x2-x1) == abs(y2-y1) && points[x2].contains(y1) && points[x1].contains(y2)){
              squares += count * points[x2][y1] * points[x1][y2];
            }
          }
        }
      return squares;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */