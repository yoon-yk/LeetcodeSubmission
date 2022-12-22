class MyCalendar {
public:
    set<pair<int, int>> cal;
    
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto lb = cal.lower_bound({start, end});
        if (lb!=cal.begin() && prev(lb)->second > start) return false;
        if (lb!=cal.end() && lb->first < end) return false;
        cal.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */