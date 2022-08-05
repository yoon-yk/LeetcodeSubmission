class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashM; // value:idx
        int counter;
        
        
        for (int i=0; i<nums.size(); i++) {
            counter = target - nums[i];
            if (hashM.count(counter))
                return {i, hashM[counter]};
            hashM[nums[i]] = i;
        }
        
        return {};
    }
};