class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numSet;
        for(auto i:nums)
            numSet.insert(i);
        return (numSet.size() < nums.size());
    }
};