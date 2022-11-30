class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        for (int i=1; i<n; i++){
            if (nums[minIdx] > nums[i]) minIdx = i;
            if (nums[maxIdx] < nums[i]) maxIdx = i;
        }
        
        int first = minIdx, second = maxIdx;
        if (first > second) swap(first, second);
        // first <= second
        
        int ans = min(second+1, 
                      min(first + 1 + n-second, n-first));
        
        return ans;
    }
};