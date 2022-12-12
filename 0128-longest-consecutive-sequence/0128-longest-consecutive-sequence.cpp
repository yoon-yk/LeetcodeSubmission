class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int & i : nums) hashSet.insert(i);
        
        int ans = 0;
        for (auto & n : hashSet) {
            if (hashSet.count(n-1)) continue;
            int curN = n, cnt = 0;
            while (hashSet.count(curN)) {
                curN++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};