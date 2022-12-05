class Solution {
public:
    vector<int> nums;
    vector<bool> visited;
    
    bool dfs(int start, int cur, int length, int cnt) {
        if (cnt==3) return true;
        if (cur==length) return dfs(0, 0, length, cnt+1);
        for(int i=start; i<nums.size(); i++) {
            if (visited[i]) continue;
            if (cur + nums[i] <= length) {
                visited[i] = true;
                if (dfs(i + 1, cur + nums[i], length, cnt)) return true;
                visited[i] = false;
            }
            if(cur==0 || cur+nums[i]==length) return false;
            while(i+1<nums.size() && nums[i+1]==nums[i]) i++;
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        nums = matchsticks;
        int n = matchsticks.size();
        visited.resize(n);
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4!=0) return false;
        sum /= 4;
        if (*max_element(nums.begin(), nums.end()) > sum) return false;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        return dfs(0, 0, sum, 0);
    }
};