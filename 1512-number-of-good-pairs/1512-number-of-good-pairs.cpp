class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> count(101, 0);
        for (int & i : nums) ++count[i];
        for (int & i : count) {ans += ((i * (i-1))>>1);}
        
        return ans;
    }
};