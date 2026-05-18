class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      //koko needs to eat somewhere between 1 and maxPileSize bananas per hour. Koko will need to eat the max pile of bananas if the number of hours she has is equal to the number of piles, since she can only eat 1 pile per hour.
      //we can do a binary search on the number of banas koko may want to eat per hour, to calculate the amount of time it took for koko to eat bananas we can loop through the piles and tally up the amount of time it took to eat each pile, which is ceil((double)pile/eating_speed).
      //we could sort piles to get max but that would be O(nlogn), lets just do an O(n) scan to find max. then we can do the binary search in O(logn) along with checking the speed of checking piles which is O(n) for a total time completity of O(nlogn).
      //space complexity O(1)
      int largestPile = 0;

      for(int& pile : piles){
        largestPile = max(largestPile,pile);
      }

      int L = 1;
      int R = largestPile;
      int bph = INT_MAX;
      while(L <= R){
        int M = (L+R)/2;
        
        if(canEat(M,piles,h)){ //if koko can eat all the bananas within this time, eat slower (less bph)
          bph = min(bph,M);
          R = M-1;
        } else{ //koko cannot eat this many bananas, eat faster. (more bananas per hour)
          L = M+1;
        }
      }
      return bph;
    }

    bool canEat(int speed, vector<int>& piles, int h){

      for(int& pile : piles){
        h -= ceil((double)pile/(double)speed);
        if(h < 0) return false;
      }
      return true;
    }


};