class Logger {
public:
    unordered_map<string, int> mp;
    queue<string> Q;
    
    Logger() {}
    
    bool shouldPrintMessage(int timestamp, string message) {
        while (!Q.empty() && timestamp - mp[Q.front()] >= 10) {
            mp.erase(Q.front());
            Q.pop();
        }
        if (mp.count(message)) return false;
        mp[message] = timestamp;
        Q.push(message);
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */