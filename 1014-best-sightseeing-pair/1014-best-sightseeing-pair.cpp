class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        /*
        (values[i] + i) + (values[j] - j)
        */
        
        int maxL = values[0], ans = 0;
        for (int i=1; i<values.size(); ++i) {
            ans = max(maxL + values[i] - i, ans);
            if (maxL < values[i] + i) maxL = values[i] + i;
        }
        return ans;
    }
};