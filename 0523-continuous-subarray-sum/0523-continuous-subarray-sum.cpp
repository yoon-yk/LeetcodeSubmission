class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), prefixSum = 0;
        unordered_map<int, int> mp;
        for (int i=0; i<n; i++) {
            prefixSum += nums[i];
            prefixSum %= k;
            
            if (prefixSum == 0 && i) return true;
            
            if (!mp.count(prefixSum))
                mp[prefixSum] = i;
            else if (i-mp[prefixSum] > 1) 
                return true;
        }
        
        /*
          [ 23,  2,  4, 6,   7]
        [0, 23, 25, 29, 35, 42]
        */

        return false;
    }
};