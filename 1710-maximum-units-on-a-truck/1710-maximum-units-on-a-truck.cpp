class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // containing the maximum units?
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });
        
        int cap = truckSize;
        int ans = 0;
        for (auto & b : boxTypes) {
            if (cap-b[0] >= 0) {
                cap -= b[0], ans += b[0]*b[1];
            } else {
                ans += cap * b[1];
                cap = 0;
                break;
            }
        }
        
        return ans;
    }
};