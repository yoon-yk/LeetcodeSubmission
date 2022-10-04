class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        
        vector<int> EDS(n, 0);
        vector<int> prev(n);
        
        int maxSize = 0, maxIdx = 0;
        int maxSubsetIdx;
        
        for (int i=0; i<n; i++) {
            
            maxSubsetIdx = i;
            prev[i] = i;
            EDS[i] = 0;
            
            for (int k=0; k<i; k++) {
                if (nums[i] % nums[k] == 0 && 
                    EDS[maxSubsetIdx] < EDS[k]) {
                        maxSubsetIdx = k;
                }
            }
            
            EDS[i] = EDS[maxSubsetIdx] + 1;
            prev[i] = maxSubsetIdx;
                        
            if (maxSize < EDS[i]) {
                maxSize = EDS[i];
                maxIdx = i;
            }
        }
        
        vector<int> res(maxSize);
        int resIdx = maxSize-1;
        int prevIdx = maxIdx;
        
        while (resIdx > -1) {
            res[resIdx] = nums[prevIdx];
            prevIdx = prev[prevIdx];
            resIdx--;
        }
        
        return res;
    }
};