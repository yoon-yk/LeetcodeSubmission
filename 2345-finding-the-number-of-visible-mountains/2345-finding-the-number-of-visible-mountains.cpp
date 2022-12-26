class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        
        /* 
        *   We sort the array - position of the left-bottom triangle from nearest to zero to farthest.
        *   If they have the same position, the higher peak will come first
        */
        
        sort(peaks.begin(), peaks.end(), [&](vector<int>& v1, vector<int>& v2) {
            int p1 = v1[0] - v1[1];
            int p2 = v2[0] - v2[1];
            if (p1 == p2) return v1[1] > v2[1]; // bigger mountain first
            return p1 < p2;
        });

        
        int res = 0, cur = 0, dup = 0, last = 0;
        
        for(vector<int>& peak: peaks) {
            int coordinate = peak[0] + peak[1];
            
            /* 
            *   A mountain considers as visible when sum(height, position) is higher than previous one
            *   A mountain considers as visible when there is no duplicate mountain
            */
            
            if (coordinate > cur) {
                res += 1;
                cur = coordinate;
                last = peak[0];
            } else if(coordinate == cur && last == peak[0]) {
                dup += 1;
                last = 0;
            }
        }
        
        return res - dup;
    }
};