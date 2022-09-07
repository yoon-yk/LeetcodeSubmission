class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        
        // brute force
        int curN = nums[0], idx = 0, missing = 0;
        while (idx < nums.size()) {
            if (curN == nums[idx])
                idx++;
            else missing++;
            if (missing == k)
                break;
            curN ++;
        }
        
        for (missing++; missing<k; missing++)
            curN ++;
    
        return curN;
    }
};