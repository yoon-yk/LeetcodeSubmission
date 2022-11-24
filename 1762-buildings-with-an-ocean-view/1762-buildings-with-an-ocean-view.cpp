class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int maxHeight = -1;
        vector<int> ans;
        for (int i=n-1; i>=0; i--) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
                ans.push_back(i);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};