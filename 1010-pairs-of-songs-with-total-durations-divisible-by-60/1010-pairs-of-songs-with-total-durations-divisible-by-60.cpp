class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        int curTime, cnt = 0;
        vector<int> remainders(60, 0);
        for (int i=0; i<n; i++) {
            curTime = time[i] % 60;
            if (curTime == 0)
                cnt+= remainders[0];
            else 
                cnt+= remainders[60-curTime];
            remainders[curTime]++;
        }

        return cnt;
    }
};