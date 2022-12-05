class Solution {

    public:
    int side;

    bool makesquare(vector<int>& nums) {
        
        
        if (nums.size() == 0)
            return false;
        
        int l = nums.size();
        int perimeter = 0;
        for (int i=0; i<l; i++)
            perimeter += nums[i];
        
        if (perimeter % 4 != 0) return false;
        side = (perimeter >> 2);
        if (*max_element(nums.begin(), nums.end()) > side) return false;
        
        unordered_map<int, unordered_map<int, bool>> memo;
    
        return (recurse(nums, (1 << l)-1, 0, memo));
    };
    
    bool recurse(vector<int>& nums, int mask, int sidesDone,unordered_map<int, unordered_map<int, bool>>& memo) {
        int total = 0;
        int l = nums.size();
        
        pair<int, int> memoKey = pair(mask, sidesDone);
        
        for (int i=l-1; i>=0; i--) {
            if ((mask & (1 << i)) == 0)
                total += nums[l-1-i];
        }
        
        if (total > 0 && (total % side == 0))
            sidesDone++;
        
        if (sidesDone == 3)
            return true;
        
        if (memo[memoKey.first].count(memoKey.second))
            return memo[memoKey.first][memoKey.second];
        
        bool ans = false;
        int c = total/side;
        int rem = side * (c+1) - total;
        
        for (int i=l-1; i>=0; i--) {
            if (nums[l-1-i] <= rem && 
               ((mask&(1 << i)) > 0)) {
                if (recurse(nums, mask ^ (1<<i), sidesDone, memo)) {
                    ans = true;
                    break;
                }
            }
        }
        
        memo[memoKey.first][memoKey.second] = ans;
        return ans;
    }
};