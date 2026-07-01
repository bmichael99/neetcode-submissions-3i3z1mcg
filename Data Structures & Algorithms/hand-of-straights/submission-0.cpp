class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      if(groupSize == 1) return true;
      //n = groupsize indicates we want hand.size()/n groups of n size.
      //hand.size() % groupSize == 0, or return false
      sort(hand.begin(),hand.end());
      if(hand.size() % groupSize != 0){
        return false;
      }
      unordered_multimap<int,int> groups;
      //a group should always have the key as the largest value in the group, the second value is the size of the group, once the size of the group is equal to groupSize we pop that group from groups. If groups is not equal to 0 at the end of looping through hand then return false. If a group does not exist for us to insert a value into then make one
      for(int i = 0; i < hand.size();i++){
        auto group = groups.find(hand[i]-1);
        if(group != groups.end()){
          int size = group->second;
          size++;
          
          groups.erase(group);
          if(size != groupSize){
            groups.insert({hand[i],size});
          }
        }else{
          groups.insert({hand[i],1});//create group with top card as hand[i] and size of 1.
        }
      }
      return groups.size() == 0;
    }
};