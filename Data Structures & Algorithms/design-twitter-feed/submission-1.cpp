//easiest approach is probably to just build the newsFeed every time it's requested instead of trying to maintain it.
//brute force approach is to just maintain a map for each userid and their posts, also keep a map for who a user follows.
//maxHeap for building newsfeed
//TC: O(nlogn)
//SC: O(N*m + N + m) where N is the number of people a user is following and m is how many tweets they have, this is the maxHeap for newsfeed.
class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> users; //users and their tweets/timestamp
    unordered_map<int,unordered_set<int>> following; //users and who they're following
    int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
      following[userId].insert(userId); //make sure user is following themselves
      users[userId].push_back({tweetId,this->time});
      this->time++;
    }
    
    vector<int> getNewsFeed(int userId) {
      priority_queue<pair<int,int>> maxHeap; //larger time is most recent
    
      for(const int& following_id : following[userId]){
        for(pair<int,int>& tweets : users[following_id]){
          maxHeap.push({tweets.second,tweets.first});
        }
      } 
      vector<int> newsFeed;
      for(int i = 0; i < 10 && !maxHeap.empty(); i++){
        newsFeed.push_back(maxHeap.top().second);
        maxHeap.pop();
      }
      return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        if(!users.contains(followerId)){
          users[followerId] = {};
        }
        if(!users.contains(followeeId)){
          users[followeeId] = {};
        }
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