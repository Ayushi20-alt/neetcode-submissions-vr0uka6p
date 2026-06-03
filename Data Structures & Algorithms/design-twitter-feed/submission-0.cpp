class Twitter {
    unordered_map<int, set<int>>friends;
    int curr = 0;
    priority_queue<vector<int>>timeline;
public:
    Twitter() {
        friends.clear();
        curr = 0;
        timeline = priority_queue<vector<int>>();
    }
    
    void postTweet(int userId, int tweetId) {
        // curr is a timestamp
        timeline.push({curr++, tweetId, userId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<vector<int>> userTimeLine = timeline; // so we dont 
        // disturb original timeline
        int n = 0; // to show only 10 items
        while(!userTimeLine.empty() && n < 10){
            auto topTweet = userTimeLine.top();
            userTimeLine.pop();
            if(topTweet[2] == userId || friends[userId].count(topTweet[2])){
                ans.push_back(topTweet[1]);
                n++;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
    }
};
