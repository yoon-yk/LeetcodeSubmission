class Element {
    public:
        int value;
        int row;
        int col;
    Element(int val, int r, int c) {
        value = val; row = r; col = c;
    }
};

class Comparator {
    public :
        bool operator() (const Element& A, const Element& B) {
            return A.value > B.value;
        }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<Element, vector<Element>, Comparator> pq;
        int m_row = matrix.size(), m_col = matrix[0].size();
        
        for (int i=0; i<m_row; i++) {
            for (int j=0; j<m_col; j++) {
                pq.push(Element(matrix[i][j],i,j));
            }
        }
        
        for (int i=0; i<k-1; i++) {
            pq.pop();
        }
        
        return pq.top().value;
    }
};