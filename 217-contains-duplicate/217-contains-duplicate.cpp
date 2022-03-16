class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int, int> hashT;
        for (int i=0; i<nums.size(); i++){
            if (hashT.find(nums[i]) != hashT.end())
                return true;
            hashT[nums[i]] = i;
        }
        return false;
    }
};