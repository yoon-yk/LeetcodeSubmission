class Solution {
public:
    int countPrimes(int n) {
        if (n < 2) return 0;
        vector<int> nums(n, true);
        nums[0] = false, nums[1] = false;
        for (int i=2; i<n; ++i) {
            if (!nums[i]) continue;
            for (int j=i+i; j<n; j+=i) 
                nums[j] = false;
        }
        
        int ans = 0;
        for (int &i : nums) ans += i;
        
        return ans;
    }
};