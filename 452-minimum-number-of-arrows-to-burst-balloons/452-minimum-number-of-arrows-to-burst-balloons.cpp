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
        
        vector<int> curInterval(2);
        curInterval[0] = points[0][0], curInterval[1] = points[0][1];
        int cnt = 1;
        
        int n = points.size();
        for (int i=1; i<n; i++) {
            if (points[i][0] <= curInterval[1]) {
                curInterval[0] = min(points[i][0], curInterval[0]);
                curInterval[1] = min(points[i][1], curInterval[1]); 
            }
            
            else {
                curInterval[0] = points[i][0];
                curInterval[1] = points[i][1];
                cnt++;
            }
        }
        
        return cnt;
    }
};