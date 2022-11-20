class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int curN;
        deque<int> dq;
        vector<int> ans;
        
        for (int i=0; i<nums.size(); i++) {

            curN = nums[i];
            if (!dq.empty() && (i-dq.front()+1) > k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < curN)
                dq.pop_back();
            dq.push_back(i);
            if (i >= k-1) ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};