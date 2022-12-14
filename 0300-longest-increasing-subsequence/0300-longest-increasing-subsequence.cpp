class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
 
        for (int i=1; i<nums.size(); ++i) {
            int num = nums[i];
            auto it = lower_bound(sub.begin(), sub.end(), num);
            if (it == sub.end()) sub.push_back(num);
            else *it = num;
            
        }
        return sub.size();
    }
};