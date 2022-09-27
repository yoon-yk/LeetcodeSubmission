class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> arr(n, INT_MAX);
        
        int dist = INT_MAX;
        for (int i=0; i<n; i++) {
            if (s[i] == c) {
                dist = 0;
            } else if (dist != INT_MAX){
                dist++;
            }
            arr[i] = min(arr[i], dist);
        }
        
        dist = INT_MAX;
        for (int i=n-1; i>=0; i--) {
            if (s[i] == c) {
                dist = 0;
            } else if (dist != INT_MAX){
                dist++;
            }
            arr[i] = min(arr[i], dist);
        }
        
        return arr;
    }
};