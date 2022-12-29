class MyCalendarTwo {
public:
    map<int, int> bks;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        ++bks[start], --bks[end];
        bool ans = true;
        
        int curB = 0;
        for (auto [date,f] : bks) {
            curB += f;
            if (curB > 2) {ans = false; break;}
        }
        
        if (!ans) 
            --bks[start], ++bks[end];
        
        return ans;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */