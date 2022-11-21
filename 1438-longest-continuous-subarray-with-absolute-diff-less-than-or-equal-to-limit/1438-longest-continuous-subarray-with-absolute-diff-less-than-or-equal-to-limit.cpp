class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), start = 0, ans = 0;
        deque<int> minD, maxD;
        for (int end = 0; end < n; end++) {
            int curN = nums[end];
            
            while (!minD.empty() && nums[minD.back()] > curN)
                minD.pop_back();
            
            while (!maxD.empty() && nums[maxD.back()] < curN)
                maxD.pop_back();
            
            minD.push_back(end);
            maxD.push_back(end);
            
            // start 줄이기
            int minN = nums[minD.front()], maxN = nums[maxD.front()];
            while (abs(maxN - minN) > limit) {
                if (nums[start] == minN) minD.pop_front(); 
                if (nums[start] == maxN) maxD.pop_front();
                start++;
                minN = nums[minD.front()], maxN = nums[maxD.front()];
            }
            
            ans = max(end-start+1, ans);
        }
        return ans;
        
    }
};