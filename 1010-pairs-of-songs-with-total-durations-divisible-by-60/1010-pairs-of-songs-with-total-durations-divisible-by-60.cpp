class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int curTime, cnt = 0;
        unordered_map<int, int> hashM;
        for (int i=0; i<n; i++) {
            curTime = time[i] % 60;
            if (curTime == 0 && hashM[0] > 0)
                cnt+= hashM[0];
            else if (hashM.count(60-curTime)) 
                cnt+= hashM[60-curTime];
            hashM[curTime]++;
        }

        return cnt;
    }
};