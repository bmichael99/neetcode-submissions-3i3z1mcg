
class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> users; //user id, [{time_stamp,tweets}]
    unordered_map<int,unordered_set<int>> following; //userid, [userid of person they're following]
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        following[userId].insert(userId);
        users[userId].push_back({this->time,tweetId});
        this->time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> maxHeap; //time,tweetId

        for(int followingId : following[userId]){
          for(int i = users[followingId].size()-1; i >= max(0,(int)users[followingId].size()-1-10); i--){
            maxHeap.push(users[followingId][i]);
          }
        }
        vector<int> newsFeed;
        for(int i = 0; i < 10 && !maxHeap.empty();i++){
          newsFeed.push_back(maxHeap.top().second);
          maxHeap.pop();
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
      if(followerId == followeeId) return;
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */