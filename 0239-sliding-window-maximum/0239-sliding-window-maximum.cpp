class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> maxN;
        vector<int> ans;
        for (int i=0; i<nums.size(); i++) {
            while (!maxN.empty() && nums[maxN.back()] < nums[i])
                maxN.pop_back();
            
            while (!maxN.empty() && i-maxN.front()+1> k)
                maxN.pop_front();
            
            maxN.push_back(i);
            
            if (i>=k-1) ans.push_back(nums[maxN.front()]);
        }
        
        return ans;
    }
};