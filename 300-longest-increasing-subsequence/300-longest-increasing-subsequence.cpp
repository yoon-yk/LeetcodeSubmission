class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> piles;
        for (int & num : nums) {
            int idx = lower_bound(piles.begin(), piles.end(), num) - piles.begin();
            if (idx == piles.size()) piles.push_back(num);
            else piles[idx] = num;
        }
        
        return piles.size();
    }
};