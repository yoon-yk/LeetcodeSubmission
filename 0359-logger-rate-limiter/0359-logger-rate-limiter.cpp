class Logger {
public:
    /** Initialize your data structure here. */
    Logger(): curr{}, prev{}, init_time{0} {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp >= init_time+10) {
            init_time = timestamp;
            prev = curr;
            curr.clear();
        }
        
        if (curr.count(message) || 
            (prev.count(message) && prev[message]+10 > timestamp)) 
            return false;
        
        curr[message] = timestamp;
        return true;
    }
    
    // holds messages in the last 10s since init_time
    unordered_map<string, int> curr;
    // holds messages in the last 10s before init_time
    unordered_map<string, int> prev;
    // timestamp beginning the countdown to 10s
    int init_time;
};
