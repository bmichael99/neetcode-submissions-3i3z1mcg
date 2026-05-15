class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
      vector<pair<int,int>> cars;

      for(int i = 0; i < position.size();i++){
        cars.push_back({position[i],speed[i]});
      }

      sort(cars.rbegin(),cars.rend());
      stack<double> fleets_speed;

      for(pair<int,int>& car : cars){
        double time_to_finish = (double)(target-car.first)/car.second; //target-position / speed,
        
        //if there are no fleets yet or the top time is faster than the current car.
        //we don't need to do anything if the car in front is slower, we form a fleet with that car so we can just skip over the current car and do nothing.
        if(fleets_speed.empty() || (!fleets_speed.empty() && fleets_speed.top() < time_to_finish)){
          fleets_speed.push(time_to_finish);
        }
      }
      return fleets_speed.size();
    }
};