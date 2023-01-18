class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), ans = n+1, sum = 0, tt, idx;
        vector<int> psum;
        psum.push_back(0);
        /*
           0, 1, 2, 3,  4,  5
        0, 2, 5, 6, 8, 12, 15
        
        sum - tt >= target;
        sum - target >= tt;
        */
        
        for (int i=0; i<n; ++i) {
            if (nums[i] >= target) return 1;
            sum += nums[i];
            tt = sum-target;
            psum.push_back(sum);
            
            auto it = upper_bound(psum.begin(), psum.end(), tt);
            if (it == psum.begin() || *prev(it) > tt) continue;
            idx = it-psum.begin()-1;
            if (ans > i-idx+1) ans = i-idx+1;
            
        }
        return ans == n+1 ? 0 : ans;
    }
};