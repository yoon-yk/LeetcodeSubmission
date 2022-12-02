class Twitter {
public:
    
    int time = 0;
    typedef pair<int, int> Tweet; // time, tId
    
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<Tweet>> tweets;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        Tweet nt(time++, tweetId);
        tweets[userId].push_back(nt);
    }
    
    vector<int> getNewsFeed(int userId) {
        
        priority_queue<Tweet, vector<Tweet>, greater<Tweet>> pq; // minheap
        for (auto & tw : tweets[userId]) {
            pq.push(tw);
            if (pq.size() > 10) pq.pop();
        }
        
        for (auto& nei : following[userId]) {
            for (auto it = tweets[nei].rbegin(); it != tweets[nei].rend(); it++) {
                if (pq.size() == 10 && it->first < pq.top().first) break;
                pq.push(*it);
                if (pq.size() > 10) pq.pop();
            }
        }
        
        vector<int> ret;
        while (!pq.empty()) {
            ret.push_back(pq.top().second); // time 작은 것부터 빼기 
            pq.pop();
        }
        reverse(ret.begin(), ret.end());
        
        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
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