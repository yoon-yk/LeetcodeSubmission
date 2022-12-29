class MyCalendarThree {
public:
    map<int, int> bks;
    MyCalendarThree() {
        
    }
    
    int book(int s, int e) {
        ++bks[s], --bks[e];
        int sum = 0, ans = 0;
        for (auto &[time, freq] : bks) {
            sum += freq;
            ans = max(ans, sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */