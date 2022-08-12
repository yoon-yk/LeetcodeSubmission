class Solution {
public:
    
    struct Point {
        int x;
        int y;
        int val;
        Point (int _x, int _y, int _val) : x(_x), y(_y), val(_val) {};
    };
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        auto compare=[] (Point*& a, Point*& b) {
            return a->val > b->val;
        };
        
        priority_queue<Point*, vector<Point*>, decltype(compare)> pq(compare);
        
        for (int i=0; i<min(k, (int)matrix.size()); i++){
            pq.push(new Point(i,0,matrix[i][0]));
        }
        
        int minV;
        Point* curPoint;
        for (int i=0; i<k; i++) {
            curPoint = pq.top(); pq.pop();
            minV = curPoint->val;
            if (curPoint->y + 1 < matrix[0].size()) {
                pq.push(new Point(curPoint->x, curPoint->y+1, matrix[curPoint->x][curPoint->y+1]));
            }
        }
        
        return minV;
        
    }
};