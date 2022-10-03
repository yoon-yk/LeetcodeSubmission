class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> EDS(n);
        int maxSize = 0, maxIdx = 0;

        for (int i=0; i<n; i++) {
            
            vector<int> maxSubset;
            
            for (int k=0; k<i; k++) {
                if (nums[i] % nums[k] == 0 && 
                    maxSubset.size() < EDS[k].size())
                    maxSubset = EDS[k];
            }
            
            maxSubset.push_back(nums[i]);
            EDS[i] = maxSubset;
            
            if (maxSize < EDS[i].size()) {
                maxSize = EDS[i].size();
                maxIdx = i;
            }
        }
        
        return EDS[maxIdx];
    }
};