class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return (pow(a[0], 2) + pow(a[1], 2)) < (pow(b[0], 2) + pow(b[1], 2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), compare);

        vector<vector<int>> ans;
        for (int i=0; i<k; i++) ans.push_back(points[i]);
        return ans;
    }
};