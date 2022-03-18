class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if (nums.size()<3) return answer;
        
        // Sort
        sort(nums.begin(), nums.end());
        
        // Two pointer
        int target, left, right;
        for (int i=0; i<nums.size()-2; i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            target = -1 * nums[i];
            left = i+1; 
            right = nums.size()-1;
            while (left < right){
                 if (nums[left] + nums[right] == target) {
                    vector<int> res;
                    res.push_back(nums[left]); res.push_back(nums[right]); 
                    res.push_back(nums[i]);
                    answer.push_back(res);
                    left++;
                    while (nums[left] == nums[left-1] && (left < right)) left++; //**
                }
                else if (nums[left] + nums[right] > target) right--;
                else left++;
            }
        }
        return answer;
        
    }
};