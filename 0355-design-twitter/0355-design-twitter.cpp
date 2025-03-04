class Twitter {
private:
    int globalTime;
    struct Tweet {
        int id;        // Tweet ID
        int time;      // Tweet timestamp
        Tweet(int tweetId, int timestamp) : 
            id(tweetId), time(timestamp) {}
    };
    
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int, int>>> userTweets;
    
public:
    Twitter() {
        globalTime = 0;
    }
    void postTweet(int userId, int tweetId) {
        // Add tweet to user's tweet list with current global timestamp
        userTweets[userId].push_back({globalTime++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Ensure the user follows themselves
        if (followMap.find(userId) == followMap.end()) {
            followMap[userId].insert(userId);
        } else if (followMap[userId].find(userId) == followMap[userId].end()) {
            followMap[userId].insert(userId);
        }
        
        // Collect tweets from all followed users
        vector<pair<int, int>> allTweets;
        for (int followedId : followMap[userId]) {
            allTweets.insert(
                allTweets.end(), 
                userTweets[followedId].begin(), 
                userTweets[followedId].end()
            );
        }
        
        // Sort tweets by timestamp in descending order
        sort(allTweets.begin(), allTweets.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });
        
        // Collect top 10 tweet IDs
        vector<int> newsFeed;
        for (int i = 0; i < min(10, (int)allTweets.size()); i++) {
            newsFeed.push_back(allTweets[i].second);
        }
        
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // Cannot unfollow self
        if (followerId == followeeId) return;
        
        // Remove followee from follower's following list
        followMap[followerId].erase(followeeId);
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