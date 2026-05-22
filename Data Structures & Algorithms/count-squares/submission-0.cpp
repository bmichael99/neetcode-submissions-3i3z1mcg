class CountSquares {
public:
    //using the point passed to count as the starting point, check if any points in the hash map are diagonal to this point, this is the starting point for forming our square, and without it we don't have a square. If we find a point that is diagonal then we can now check if we have the poitns to form a square, to do so we use basic math to check the hash map for the other 2 points, we can determine the count based on if they exist and how many of each there are.
    unordered_map<int, unordered_map<int,int>> squares;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        squares[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        //diagonal for square, check if y2-y1 and x2-x1 have a slope of 1, that is (y2-y1)/(x2-x1) == 1 OR rather (y2-y1) == (x2-x1)
      int x1 = point[0];
      int y1 = point[1];
      int sol = 0;
      for (auto& [x2, yMap] : squares) {
          for (auto& [y2, cnt] : yMap) {
            if(x1 == x2 || y1 == y2) continue; //ignore points that could not be diagonal
            if((abs(y2-y1) == abs(x2-x1)) && squares[x2].contains(y1) && squares[x1].contains(y2)){
                sol += (cnt * squares[x2][y1] * squares[x1][y2]);
            }
          }
      }
      return sol;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */