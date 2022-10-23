class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int expected = (int) (pow(n, 2) + n) / 2; // gausses property 
        int duplicate = 0, actualSum = 0;
        set<int> sset;
        for (int i = 0; i < n; i++) {
            if (sset.count(nums[i])) duplicate = nums[i];
            sset.insert(nums[i]);
            actualSum += nums[i];
        }
        int differential =  expected - actualSum;
        return {duplicate, duplicate + differential};
    }
};