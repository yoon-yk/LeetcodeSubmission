class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
                
        unordered_map<int, int> hashM; // prefixSum : index
        hashM[0] = 1;

        int curSum = 0, cnt = 0;
        for (int i=0; i<nums.size(); i++) {
            curSum += nums[i];
            int complement = curSum - k;
            if (hashM.count(complement)) {
                cnt += hashM[complement];
            } 
            hashM[curSum]++;
        }
        
        return cnt;
    }
};