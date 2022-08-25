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
        
        // for (int i=0; i<26; i++) {
        //     if (begin[i] < 0) continue;
        //     cout << (char)(i+'a') << "| start- : " << begin[i] << "::" << end[i] << endl;
        // }
        
        
        vector<int> ans;
        int curIdx, startIdx = -1, endIdx = -1;
        for (int i=0; i<s.length(); i++) {
            curIdx = s[i]-'a';
            if (startIdx == -1) {
                startIdx = begin[curIdx];
                endIdx = end[curIdx];
            }
            else if (i < endIdx && end[curIdx] > endIdx){
                endIdx = end[curIdx];
            }
            // cout << s[i] << "::" << startIdx << "::" << endIdx << endl;
            
            if (i == endIdx){
                // cout << "case" << i << "/" << endIdx << endl;
                ans.push_back(endIdx-startIdx+1);
                startIdx = -1;
                endIdx = -1;
            }
            
        }
        
        return ans;
        
        
    }
};