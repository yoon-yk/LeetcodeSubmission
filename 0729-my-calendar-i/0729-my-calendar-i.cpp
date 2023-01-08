class MyCalendar {
public:
    set<pair<int, int>> v;

    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = v.lower_bound({start, end});
        // next
        if (it != v.end() && end > it->first) return false;
        if (it != v.begin() && start < prev(it)->second) return false;

        v.insert({start,end});
        return true;

        /*
        [25,32] [33,41] [47,50] 
        */
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */