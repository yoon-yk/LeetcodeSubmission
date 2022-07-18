class Solution {
public:
        
    int subsetXORSum(vector<int>& nums) {

        int ans = 0;
        int subsetBit = pow(2, nums.size());
        
        for (int subset=1; subset<subsetBit; subset++) {
            int currXOR = 0;
            for (int i=0, bits=subset; i < nums.size(); i++, bits >>= 1) {
                if (bits & 1) {
                    currXOR ^= nums[i];
                }
            }
            ans += currXOR;
        }
    return ans;
    }
   
};

