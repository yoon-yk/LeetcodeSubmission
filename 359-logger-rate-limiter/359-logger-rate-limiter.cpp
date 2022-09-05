class Logger {
public:
    
    unordered_map<string, int> m;
    
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if (m.count(message) && timestamp < m[message])
            return false;
         
        m[message] = timestamp+10;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */