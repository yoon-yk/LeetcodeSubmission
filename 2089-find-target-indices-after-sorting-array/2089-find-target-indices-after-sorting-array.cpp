class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        // edge case : # == 1
        if (nums.size()==0) return {};
        if (nums.size()==1 && target==nums[0]) return {0};

        vector<int> ans;
        int start = 0, end = nums.size()-1, mid;
        
        while (start < end) {
            mid = start + ((end-start+1)>>1);
            if (nums[mid] == target) {
                while (nums[start]!=target) start++;
                while (nums[end]!=target) end--;
                for (int i=start; i<=end; i++) ans.push_back(i);
                return ans;
            }
            if (target < nums[mid]) 
                end = mid-1;
            else start = mid;
        }
        
        if (start == end && nums[start] == target) {
            ans.push_back(start);
        }
                
        return ans;
        
    }
};