class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        vector<int> minQ, maxQ;
        
        int n = nums.size();
        for (int i=0; i<n; i++){
            while (!minQ.empty() && nums[minQ.back()] > nums[i])
                minQ.pop_back();
            while (!maxQ.empty() && nums[maxQ.back()] < nums[i])
                maxQ.pop_back();
            
            minQ.push_back(i);
            maxQ.push_back(i);
        }
        
        int first = minQ[0], second = maxQ[0];
        if (first > second) swap(first, second);
        // first <= second
        
        int ans = min(second+1, 
                      min(first + 1 + n-second, n-first));
        
        return ans;
    }
};