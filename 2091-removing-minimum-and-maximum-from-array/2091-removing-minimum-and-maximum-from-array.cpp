class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minI = 0, maxI = 0, n = nums.size();
        for (int i=1; i<n; ++i) {
            if (nums[minI] > nums[i]) {
                minI = i;
            } else if (nums[maxI] < nums[i]) {
                maxI = i;
            }
        }
        
        int op1 = max(minI, maxI)+1;
        int op2 = n-min(minI, maxI);
        int op3 = minI < maxI ? minI+1 + (n-maxI) : maxI+1 + (n-minI);
                
        return min(op1, min(op2, op3)); 
    }
};