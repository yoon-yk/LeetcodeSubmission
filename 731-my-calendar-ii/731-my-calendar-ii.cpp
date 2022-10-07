class MyCalendarTwo {
public:
    
    map<int, int> mp;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        int cur = 0;
        mp[start]++, mp[end]--;
        for (auto & [idx, cnt] : mp) {
            cur += cnt;
            if (cur >= 3) {
                mp[start]--, mp[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */