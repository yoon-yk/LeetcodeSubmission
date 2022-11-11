class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        int n = coordinates.size();
        
        if (coordinates[1][0]-coordinates[0][0] == 0) {
            for (int i=1; i<n-1; i++) {
                if ((coordinates[i+1][0]-coordinates[i][0]) != 0)
                    return false;
            }
        } else {
            int s = (coordinates[1][1]-coordinates[0][1]) / (coordinates[1][0]-coordinates[0][0]);
        for (int i=1; i<n-1; i++) {
            if ((coordinates[i+1][0]-coordinates[i][0]) == 0) return false;
            if (((coordinates[i+1][1]-coordinates[i][1]) / (coordinates[i+1][0]-coordinates[i][0])) != s) return false;
        }
        }

        
        return true;
    }
};