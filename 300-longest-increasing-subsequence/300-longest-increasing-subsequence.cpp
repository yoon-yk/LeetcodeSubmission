class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // Initialize stack
        vector<int> topOfStack(nums.size(), INT_MAX);
        int currStackN = 0;
        
        // 2. Make piles of cards
        for (int i=0, j; i<nums.size(); i++) {
            int currCard = nums[i];
            int stackToPut = lower_bound(topOfStack.begin(), topOfStack.begin()+currStackN, currCard) - topOfStack.begin();
            if (stackToPut >= currStackN) currStackN++;
            topOfStack[stackToPut] = currCard;
        }
        
        return currStackN;
    }
};