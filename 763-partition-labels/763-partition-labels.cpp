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
            // cout << (char)(i +'a') << ": " << begin[i] << "|" << end[i] << endl;
            intervals.push_back({begin[i], end[i]});
        }
    
        sort(intervals.begin(), intervals.end());
        
        
        vector<int> ans;
        int startIdx = -1, endIdx = -1;
        for (auto i : intervals) {
            cout << i.first << "/" << i.second << endl;
            if (startIdx == -1) {
                cout << "case1" << endl;
                startIdx = i.first;
                endIdx = i.second;
            }
            else if (i.first > endIdx) {
                cout << "case2" << endl;
                ans.push_back(endIdx-startIdx+1);
                startIdx = i.first;
                endIdx = i.second;
            }            
            else if (i.second > endIdx) {
                cout << "case3" << endl;
                endIdx = i.second;
            }
        }
        ans.push_back(endIdx-startIdx+1);
        
        return ans;
        
        
    }
};