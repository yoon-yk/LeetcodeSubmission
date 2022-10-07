class MyCalendarThree {
public:
    /*
    vector<vector<vector<int>>> calendars;
    
    number of meeting rooms ! [1,2][4,5]
    [5, 10], [10, 20] [50, 60]
    [10, 40]
    [5, 15] [25, 55]
    
    [1,2], [4,5], [5,10], [10,20], [50,60], 
    [3,7], [10,40], 
    [4,5], [5,15], [25,55], 
    
    for each set, do a binary search to check if it's overlapped.
        --> prev elem exist && prev[1] >= cur[0]
        --> next elem exist && next[0] < cur[1] 
    if so, move on to the next set
    if not, settle down??? -> how to make it maximum
    
    if it doesn't fit anywhere, create a new one. 
    */
    
    map<int, int> diff;
    MyCalendarThree() {
    }
    
    int book(int start, int end) {
        int cur, res = 0;
        diff[start]++, diff[end]--;
        for (auto & [_, delta] : diff) {
            cur += delta;
            res = max(res, cur);
        }
        
        return res;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */