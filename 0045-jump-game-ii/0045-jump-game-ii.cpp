class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();
        if (n == 1) return 0;
        
        queue<int> Q;
        vector<int> visited(n, false);
        Q.push(0);
        visited[0] = true;
        
        int size = 0, idx = 0, cnt = 0;
        while (!Q.empty()) {
            size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                
                for (int i=0; i<=nums[cur]; i++) {
                    if (cur+i == n-1) return cnt + 1;
                    if (visited[cur+i]) continue;
                    Q.push(cur+i);
                    visited[cur+i] = true;
                }
            }
            cnt ++;
        }
        
        return cnt;
        
    }
};