class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        vector<bool> visited(n, false);
        int nextN = nums[0];
        while (1) {
            if (visited[nextN]) return nextN;
            visited[nextN] = true;
            nextN = nums[nextN];
        }
        
        return -1;
    }
};