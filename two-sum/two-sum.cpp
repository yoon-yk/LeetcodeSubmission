class Solution {
public:
    map<int, int> hashT;
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, matchNum;
        vector<int> ans;
        for(i=0; i<nums.size(); i++){
            matchNum = target - nums[i];
            if(hashT.find(matchNum)!=hashT.end()){
                ans.push_back(i);
                ans.push_back(hashT[matchNum]);
                break;
            }
            hashT[nums[i]] = i;
        }
    return ans;
    }
};