class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> maxSt;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i=0; i<2*n; i++) {
            while (!maxSt.empty() && nums[maxSt.back()] < nums[i%n]) {
                ans[maxSt.back()] = nums[i%n];
                maxSt.pop_back();
            }
            
            maxSt.push_back(i%n);
        }
        
        return ans;
    }
};