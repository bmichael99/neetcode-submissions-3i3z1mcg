class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //each pile has piles[i] bananas, koko wants to eat as slow as possible, can only eat up to 1 pile of bananas per hour.
        //binary search within 1-largestPile per hour.
        //if piles.size() == h then must eat largest pile size per hour.
        //TC: O(klogn) where k is the largest pile, n is piles.size()

        int L = 1;
        int R = 1;

        //find largest pile size for R
        for(int& pile : piles){
          R = max(R,pile);
        }
        int sol = R;
        while(L <= R){
          int M = (L+R)/2;
          //if koko can eat at this speed, try to eat slower, koko wants to eat as slow as possible
          if(canEat(M,piles,h)){
            sol = M;
            R = M-1; //decrease bph
          } else {
            L = M+1; //increase bph
          }
        }

      return sol;

    }
    //can koko eat these bananas in the given time @ provided bananas per hour
    bool canEat(int bph, vector<int>& piles, int h){

      for(int& pile : piles){
        h -= ceil((double)pile/(double)bph);

        if(h < 0) break;
      }

      return h >= 0;
    }
};