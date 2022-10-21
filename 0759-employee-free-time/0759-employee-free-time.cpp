/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    /*
    1 2 3 4 5 6 10
    + - - + + - -
    +
    --------------
    2 1 0 1 2 0 0 
    
    */
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int, int> mp;
        for (auto & sch : schedule) {
            for (auto & interval : sch) {
                mp[interval.start] ++;
                mp[interval.end]--;
            }
        }
        
        int curNJob = 0;
        int startTime = -1;
        
        vector<Interval> ans;
        for (auto& curTime : mp) {
            curNJob += curTime.second;
            if (curNJob == 0) {
                if (startTime == -1)
                    startTime = curTime.first;
            } else if (startTime!= -1) {
                ans.push_back(Interval(startTime, curTime.first));
                startTime = -1;
            }
        }
        
        return ans;
        
    }
};