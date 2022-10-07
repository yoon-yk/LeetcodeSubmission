class MyCalendarTwo {
public:
    
    map<int, int> mp;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        int cur = 0;
        if (!mp.count(start)) mp[start] = 0;
        for (auto & [idx, cnt] : mp) {
            cur += cnt;
            if (idx >= start && idx < end) {
                if (cur >= 2)
                    return false;
            }
        }
        mp[start]++, mp[end]--;
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */