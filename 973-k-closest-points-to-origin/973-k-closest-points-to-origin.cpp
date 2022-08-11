class Solution {
public:
    
    struct Point {
        int x;
        int y;
        int dist;
        Point(int _x, int _y) : x(_x), y(_y), dist((x*x) + (y*y)) {}
    };
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        auto compare = [](Point* a, Point* b) {
            return a->dist > b->dist; // use > for min heap, < for max heap
        };
        
        vector<vector<int>> ans;
        priority_queue <Point*, vector<Point*>, decltype(compare)> pq(compare);

        
        Point* newPoint;
        for (const vector<int>& p : points) {
            newPoint = new Point(p[0], p[1]);
            pq.push(newPoint);
        }
        
        int cnt = 0;
        Point* curPoint;
        
        while (cnt++ < k) {
            curPoint = pq.top(); pq.pop();
            ans.push_back({curPoint->x, curPoint->y});
        }
        
        return ans;
    }
};