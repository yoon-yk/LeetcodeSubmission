class Solution {
public:
    
    /*
    1 3 -1 -3 5 3 6 7
    
    1
    3
    3 -1
    3 -1 -3
    5 
    5 3 
    6
    7
    
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int curN;
        deque<int> dq;
        vector<int> ans;
        
        for (int i=0; i<k; i++) {
            curN = nums[i];
            while (!dq.empty() && nums[dq.back()] < curN)
                dq.pop_back();
            dq.push_back(i);
        }

        for (int i=k-1; i<nums.size(); i++) {
    
            curN = nums[i];
            while (!dq.empty() && (i-dq.front()+1) > k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < curN)
                dq.pop_back();
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        
        return ans;
    }
};