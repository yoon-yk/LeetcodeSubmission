class Solution {
public:
    vector<vector<int>> subsets;
        
    int subsetXORSum(vector<int>& nums) {
        
        backtrack(0, nums);

        int total = 0;
        
        for (vector<int> next : subsets) {
            int sum = 0;
            for (int n : next)
                sum ^= n;
            total += sum;
        }

        return total;
    }
    
    void backtrack(int idx, vector<int>& nums){
    
        if (nums.size() == 0) return;
        
        subsets.push_back(nums);

        for (int i=idx; i<nums.size(); i++) {
            int tmp = nums[i];
            nums.erase(nums.begin()+i);
            backtrack(i, nums);
            nums.insert(nums.begin()+i, tmp);
        }
    }
};

