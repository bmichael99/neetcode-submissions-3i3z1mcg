class Solution {
public:
  int minEatingSpeed(vector<int>& piles, int h) {
    //koko wants to eat banas as slowly as possible.
    //observations: n piles cannot be greater than the number of hours, since koko can only eat one pile of banas per hour. if n == h then koko must eat the size of the largest pile per hour.
    //this means then that koko must eat between 1-maxPile banana's per hour.
    //brute force: starting from 1 banana per hour, work your way up until you find the most amount of banana's koko can eat per hour and remain under h hours.
    //optimal: binary search to find the optimal amount of banana's koko can eat per hour, searching between 1 banana and maxPile banana's. If koko can finish all banas within the selected time, increase the amount of bananas eaten per hour, if koko cannot finish them, then decrease. Whenever koko can eat the bananas, update bph.

    sort(piles.begin(),piles.end());
    int n = piles.size();
    int L = 1;
    int R = piles[n-1];
    int bph = INT_MAX; //bananas per hour
    while(L <= R){
      int M = (L+R)/2;
      if(canEat(M,piles,h)){
        R = M-1;
        bph = min(bph,M); //eat as slow as possible within h
      } else{
        L = M+1;
      }
    }
    return bph;
  }

  
  bool canEat(int b, vector<int>& piles, int h){
    for(int i = 0; i < piles.size();i++){
      h -= ceil((double)piles[i]/(double)b); 
      if(h < 0) break;
    }

    return h >= 0;
  }
};