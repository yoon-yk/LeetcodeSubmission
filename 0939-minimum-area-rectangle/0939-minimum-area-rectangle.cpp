class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        
        int ans = 0;
        int minSize = INT_MAX;
        
        sort(points.begin(), points.end());
        unordered_map<int, unordered_set<int>> pointsDict;

        for (auto& pt : points) // O(N)
            pointsDict[pt[0]].insert(pt[1]);
        
        for (int curPtr=0; curPtr<points.size(); curPtr++) {
            int curX = points[curPtr][0], curY = points[curPtr][1];
            vector<int> nextMin = {curX+1, 0};
            int nextIdx = lower_bound(points.begin(), points.end(), nextMin) - points.begin();
            for (int nextPtr=nextIdx; nextPtr < points.size(); nextPtr++) {
                int nextX = points[nextPtr][0], nextY = points[nextPtr][1];
                if (curY == nextY) continue;
                if (!pointsDict[curX].count(nextY) || 
                    !pointsDict[nextX].count(curY)) continue;
                minSize = min(minSize, abs((nextX-curX)*(nextY-curY)));
            }
            
        }      
        return (minSize == INT_MAX)? 0 : minSize;
    }
};