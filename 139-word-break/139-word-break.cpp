class Solution {
public:
    int maxLen = 0;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> dict;
        unordered_map<int, unordered_map<int, bool>> visit;
        
        for (string& str : wordDict) {
            dict.insert(str);
            maxLen = max(maxLen, (int)str.size());
        }
        
        string curStr = "";
        return backtrack(0, s, 0, curStr, dict, visit);
    }
    
    bool backtrack(int idx, string& s, int curStrBeg, string& curStr, unordered_set<string>& dict, unordered_map<int, unordered_map<int, bool>>& visit) {
        
        if (visit[curStrBeg].count(idx)) 
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
            ans |= backtrack(idx+1, s, curStrBeg, curStr, dict, visit);
            curStr.pop_back();
            
            if (dict.count(curStr)) {
                string newString;
                newString.push_back(s[idx]);
                ans |= backtrack(idx+1, s, idx, newString, dict, visit);
                newString.pop_back();
            } 
        
        }
        
        return visit[curStrBeg][idx] = ans;
        
        
    }
};