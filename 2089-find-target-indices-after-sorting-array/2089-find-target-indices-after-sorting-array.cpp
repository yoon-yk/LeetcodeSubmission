class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;        
        int lessCnt = 0, equalCnt = 0;
        for(int i=0; i<nums.size(); i++) {
            if (nums[i] < target) ++lessCnt;
            else if(nums[i] == target) ++equalCnt;
        }
                
        for (int i=0; i<equalCnt; i++)
            ans.push_back(lessCnt++);
    
        return ans;
    }
};