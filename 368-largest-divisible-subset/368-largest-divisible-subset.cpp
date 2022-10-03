class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int>> EDS(n);
        
        for (int i=0; i<n; i++) {
            
            vector<int> maxSubset;
            
            for (int k=0; k<i; k++) {
                if (nums[i] % nums[k] == 0 && 
                    maxSubset.size() < EDS[k].size())
                    maxSubset = EDS[k];
            }
            
            maxSubset.push_back(nums[i]);
            EDS[i] = maxSubset;
        }
        
        vector<int> ret;
        for (int i=0; i<n; i++)
            if (ret.size() < EDS[i].size())
                ret = EDS[i];
        return ret;
    }
};