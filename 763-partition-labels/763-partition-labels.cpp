class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> begin(26, -1);
        vector<int> end(26, -1);
        
        for (int i=0; i<s.length(); i++) {
            if (begin[s[i]-'a'] < 0)
                begin[s[i]-'a'] = i;
            end[s[i]-'a'] = i;
        }
        
        vector<pair<int, int>> intervals;

        for (int i=0; i<26; i++) {
            if (begin[i] < 0) continue;
            intervals.push_back({begin[i], end[i]});
        }
    
        sort(intervals.begin(), intervals.end());
        
        
        vector<int> ans;
        int startIdx = -1, endIdx = -1;
        for (auto &i : intervals) {
            if (startIdx == -1) {
                startIdx = i.first;
                endIdx = i.second;
            }
            else if (i.first > endIdx) {
                ans.push_back(endIdx-startIdx+1);
                startIdx = i.first;
                endIdx = i.second;
            }            
            else if (i.second > endIdx) {
                endIdx = i.second;
            }
        }
        ans.push_back(endIdx-startIdx+1);
        
        return ans;
        
        
    }
};