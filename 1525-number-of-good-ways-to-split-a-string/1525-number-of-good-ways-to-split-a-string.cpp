class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> startingFrom(n), endingAt(n);
        
        unordered_set<int> seen;
        for (int i=0; i<n; i++) {
            seen.insert(s[i]-'a');
            endingAt[i] = seen.size();
        }
        
        seen.clear();
        for (int i=n-1; i>=0; i--) {
            seen.insert(s[i]-'a');
            startingFrom[i] = seen.size();
        }
        
        int cnt = 0;
        for (int i=0; i<n-1; i++) 
            cnt += (endingAt[i] == startingFrom[i+1]);
        
        return cnt;
        
    }
};