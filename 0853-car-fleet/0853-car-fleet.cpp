class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        
        int n = speed.size();
        vector<pair<int, int>> v;
        for (int i=0; i<n; ++i) 
            v.push_back(pair(pos[i], speed[i]));
        sort(v.begin(), v.end());
        
        vector<double> time;
        double curTime;
        for (int i=0; i<n; ++i) {
            auto &[pos, speed] = v[i];
            curTime = (target-pos)/(double)speed;
            while (!time.empty() && time.back() <= curTime) time.pop_back();
            time.push_back(curTime);
        }
        
        return time.size();
    }
};