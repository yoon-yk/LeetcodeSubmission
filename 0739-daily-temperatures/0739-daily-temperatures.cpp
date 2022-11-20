class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        /*
        [73,74,75,71,69,72,76,73]
        [ 1, 1, 4, 2, 1, 1, 0, 0]
        
        */
        
        int currTp, n = temp.size(), hottest = 0;
        vector<int> ans(n, 0);
        for (int currDay=n-1; currDay>=0; currDay--) {
            currTp = temp[currDay];
            if (currTp >= hottest) {
                hottest = currTp;
            } else {
                int days = 1;
                while (temp[currDay + days] <= currTp) {
                    days += ans[currDay + days];
                }
                ans[currDay] = days;
            }
        }
        return ans;
    }
};