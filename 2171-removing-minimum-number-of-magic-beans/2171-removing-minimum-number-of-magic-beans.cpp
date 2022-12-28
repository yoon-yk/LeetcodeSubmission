class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        /*
        <1> 4 5 6
        
        2 2 3 10
        */
        
        long long sum = accumulate(beans.begin(), beans.end(), 0L);
        sort(beans.begin(), beans.end());
        
        int n = beans.size();
        long long cur, ans = sum;
        for (int i=0; i<n; ++i) {
            ans = min(ans, sum-(n-i)*(long long)beans[i]);
        }
        return ans;
    }
};