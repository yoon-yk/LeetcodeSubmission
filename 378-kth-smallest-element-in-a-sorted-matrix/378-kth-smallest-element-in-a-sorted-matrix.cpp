class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // max heap 만들기
        priority_queue<int> pq;
        
        // max heap k크기로 유지해주기
        int m_row = matrix.size(), m_col = matrix[0].size();
        for (int r=0; r<m_row; ++r) {
            for (int c=0; c<m_col; ++c) {
                pq.push(matrix[r][c]);
                
                if (pq.size() > k) {
                    pq.pop();    
                }
            }
        }
        
        return pq.top();
    }
};