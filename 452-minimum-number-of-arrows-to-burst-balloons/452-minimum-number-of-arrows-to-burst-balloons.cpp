class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        /*
        
        [[10,16],[2,8],[1,6],[7,12]]
        
        [[1,6],[2,8],[7,12], [10,16]]
        [2,6] [10,12] 

        
        [[1,2],[2,3],[3,4],[4,5]]
        
        [[1,2], [2,3]], [[3,4],[4,5]]
        [1,2][2,3] 
        [2,2] [4,4]
        
        
        */
        sort(points.begin(), points.end());

        int curOverlapEnd = points[0][1];
        int cnt = 1;
        
        int n = points.size();
        for (auto& point : points) {
            if (point[0] <= curOverlapEnd) {
                curOverlapEnd = min(point[1], curOverlapEnd); 
            }
            
            else {
                curOverlapEnd = point[1];
                cnt++;
            }
        }
        
        return cnt;
    }
};