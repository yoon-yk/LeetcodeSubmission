class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hashM;
        hashM[0] ++;
        
        int cnt = 0;
        int prefixSum = 0;
        for (int i=0; i<n; ++i) {
            prefixSum += nums[i];
            if (hashM.count(prefixSum - k))
                cnt += hashM[prefixSum-k];
            hashM[prefixSum]++;
        }
        return cnt;
    }
};