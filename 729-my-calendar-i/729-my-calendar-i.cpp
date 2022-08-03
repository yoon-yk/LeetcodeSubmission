class booking {
public:
    int start;
    int end;
    booking (int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class comparator {
public:
    bool operator() (booking a, booking b) {
        return a.start < b.start;
    }
};

class MyCalendar {
public:
    list<booking> bookings;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // check the schedule conflict
        bool conflict = false;
        for (auto b : bookings) {
            if ( b.start <= start && start < b.end ||
                 b.start < end && end <= b.end ||
                start <= b.start && b.end <= end
               ) {
                conflict = true;
                break;
            }
        }
        // if not, make one and insert
        if (conflict) return false;
        
        bookings.push_back(booking(start, end));
        
        // sort
        
        comparator cmp;
        bookings.sort(cmp);
        
        // cout << "*******" << endl;
        // for (auto b : bookings) {
        //     cout << b.start << ":" << b.end << endl;
        // }
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */