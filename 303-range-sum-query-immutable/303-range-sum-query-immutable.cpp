class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) 
            prefix.push_back(prefix[i-1]+nums[i]);
    }
    
    int sumRange(int left, int right) {
        int rSum = prefix[right];
        int lSum = (left < 1) ? 0 : prefix[left-1];
        return rSum-lSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */