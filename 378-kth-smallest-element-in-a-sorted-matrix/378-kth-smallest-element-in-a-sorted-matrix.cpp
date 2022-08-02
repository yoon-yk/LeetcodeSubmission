class Element {
    public :
        int value;
        int column;
        int row;
    Element(int v, int r, int c) {
        value = v;
        column = c;
        row = r;
    }
};

class Comparator {
    public:
    bool operator() (const Element* a, const Element* b) {
        return a->value > b->value;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // min heap 만들어주기
        priority_queue<Element*, vector<Element*>, Comparator> pq;
        
        int m_row = matrix.size(), m_col = matrix[0].size();

        // 첫번째 row 다 넣어주기
        for (int c=0; c < min(m_col, k); ++c) {
            Element* ptr = new Element(matrix[0][c], 0, c);
            pq.push(ptr);
        } 
        
        // k만큼 min heap에서 하나씩 빼면서 top아래 애도 넣어주기
        
        int r, c, val;
        for (int i=0; i < k; i++) {
            Element* curr = pq.top(); pq.pop();
            val = curr->value, r = curr->row, c = curr->column;
            if (r+1 < m_row) {
                Element* ptr = new Element(matrix[r+1][c], r+1, c);
                pq.push(ptr);
            }
        }
        
        return val;
    }
};