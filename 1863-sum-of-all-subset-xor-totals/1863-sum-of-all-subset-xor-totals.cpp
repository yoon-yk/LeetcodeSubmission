class Solution {
public:
    vector<vector<int>> subsets;
        
    int subsetXORSum(vector<int>& nums) {
        
        vector<int> idxV;
        for (int i=0; i<nums.size(); i++) idxV.push_back(i);
        
        backtrack(0, idxV);

        int total = 0;
        
        for (vector<int> next : subsets) {
            int sum = 0;
            for (int n : next)
                sum ^= nums[n];
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

