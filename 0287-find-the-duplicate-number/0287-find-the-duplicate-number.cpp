class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> visited(n, false);
        for (int n : nums) {
            if (visited[n]) return n;
            visited[n] = true;
        }
        
        return -1;
    }
};