class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        // LB 
        int start = 0, end = nums.size()-1, leftMid, rightMid;
        while (start < end) {
            leftMid = start + ((end-start)>>1);
            if (nums[leftMid] < target)
                start = leftMid + 1;
            else 
                end = leftMid;
            
        }
                
        if (nums[start]!=target) return ans;
        
        // RB
        leftMid = start;
        end = nums.size()-1;
        while (start < end) {
            rightMid = start + ((end-start+1)>>1);
            if (target < nums[rightMid])
                end = rightMid - 1;
            else start = rightMid;
        }
        
        rightMid = start;
        
        for(int i=leftMid; i<=rightMid; i++)
            ans.push_back(i);
        
        return ans;
    }
};