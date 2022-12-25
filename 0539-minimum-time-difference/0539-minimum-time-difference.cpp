class Solution {
public:
    
    int getDiff(string& time1, string& time2) {
        int t1 = ((time1[0]-'0')*10 + (time1[1]-'0'))*60 + (time1[3]-'0')*10 + (time1[4]-'0');
        int t2 = ((time2[0]-'0')*10 + (time2[1]-'0'))*60 + (time2[3]-'0')*10 + (time2[4]-'0');

        return min(abs(t1-t2), 24*60-abs((t1-t2)));
    }
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int diff, minDiff = 24*60;
        for (int i=0; i<timePoints.size(); ++i) {
            diff = getDiff(timePoints[i], timePoints[(i+1)%(timePoints.size())]);
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
};