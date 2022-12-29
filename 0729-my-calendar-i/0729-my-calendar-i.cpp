class MyCalendar {
public:
    set<pair<int, int>> cal;
    
    MyCalendar() {}
    
    /*
    [20, 30]
    
    */
    bool book(int start, int end) {
        auto it = cal.lower_bound({start, end});
        if (it != cal.begin() && start < prev(it)->second)
            return false;
        if (it != cal.end() && it->first < end)
            return false;
        cal.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */