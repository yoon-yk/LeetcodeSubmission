class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> EDS(n);
        int maxSize = 0, maxIdx = 0;

        for (int i=0; i<n; i++) {
            int maxSubsetIdx = -1;
            
            for (int k=0; k<i; k++) {
                if (nums[i] % nums[k] == 0 && 
            ((maxSubsetIdx == -1) || EDS[maxSubsetIdx].size() < EDS[k].size()))
                    maxSubsetIdx = k;
            }
            
            if (maxSubsetIdx > -1) 
                EDS[i] = EDS[maxSubsetIdx];
            EDS[i].push_back(nums[i]);

            
            if (maxSize < EDS[i].size()) {
                maxSize = EDS[i].size();
                maxIdx = i;
            }
        }
        
        return EDS[maxIdx];
    }
};