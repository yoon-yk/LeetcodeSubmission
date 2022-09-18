class Solution {
public:
    int maxLen = 0;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int len = s.size();
        unordered_set<string> dict;
        vector<vector<int>> visit(len+1, vector<int>(len+1, -1));
        
        for (string& str : wordDict) {
            dict.insert(str);
            maxLen = max(maxLen, (int)str.size());
        }
        
        string curStr = "";
        return backtrack(0, 0, s, curStr, dict, visit);
        // return true;
    }
    
    bool backtrack(int curStrBeg, int idx, string& s, string& curStr, unordered_set<string>& dict, vector<vector<int>>& visit) {
        
        if (visit[curStrBeg][idx] != -1)
            return visit[curStrBeg][idx];
        
        // cout << curStr << endl;
        if (curStr.size() > maxLen)
            return visit[curStrBeg][idx] = false;
        
        // basecase
        // if all found 
        if (idx == s.size()) 
            return visit[curStrBeg][idx] = dict.count(curStr);
        
        bool ans = false;
        
        for (int i=idx; i<s.size(); i++) {
            
            curStr.push_back(s[idx]);
            ans |= backtrack(curStrBeg, idx+1, s, curStr, dict, visit);
            curStr.pop_back();
            
            if (dict.count(curStr)) {
                string newString;
                newString.push_back(s[idx]);
                ans |= backtrack(idx, idx+1, s, newString, dict, visit);
                newString.pop_back();
            } 
        
        }
        
        return visit[curStrBeg][idx] = ans;
        
        
    }
};