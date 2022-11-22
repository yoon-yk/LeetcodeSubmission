class Solution {
public:
    
    using pop = pair<int, pair<int, int>>;
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int ans = 0;
        priority_queue<pop, vector<pop>, greater<pop>> pq; 
        for (int i=0; i<min(k, (int)matrix.size()); i++) {
            pq.push({matrix[i][0],{i, 0}});
        }
        
        int cnt = 0, val, row, col;
        while (cnt < k) {
            auto cur = pq.top(); pq.pop(); 
            val = cur.first, row = cur.second.first, col = cur.second.second;
            if (col+1 < matrix[0].size()) 
                pq.push({matrix[row][col+1], {row, col+1}});
            cnt ++;
        }
        
        return val;
    }
};