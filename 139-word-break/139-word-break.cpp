class Solution {
public:
    int maxLen = 0;
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int len = s.size();
        unordered_set<string> dict;
        
        vector<int> startingDict(26, 0);
        vector<int> visit(len+1, -1);
        
        for (string& str : wordDict) {
            dict.insert(str);
            startingDict[str[0]-'a']++;
            maxLen = max(maxLen, (int)str.size());
        }
        
        string curStr = "";
        return backtrack(0, 0, s, curStr, startingDict, dict, visit);
    }
    
    bool backtrack(int curStrBeg, int idx, string& s, string& curStr, vector<int>& startingDict, unordered_set<string>& dict, vector<int>& visit) {
        
        if (visit[curStrBeg] != -1)
            return visit[curStrBeg];
        
        if (curStr.size() > maxLen)
            return visit[curStrBeg] = false;

        if (idx == s.size()) 
            return visit[curStrBeg] = dict.count(curStr);
        
        bool ans = false;
        
        for (int i=idx; i<s.size(); i++) {
            
            char curCh = s[idx];
            
            curStr.push_back(curCh);
            ans |= backtrack(curStrBeg, idx+1, s, curStr, startingDict, dict, visit);
            curStr.pop_back();
            
            if (dict.count(curStr) && startingDict[curCh-'a'] > 0) {
                string newString;
                newString.push_back(curCh);
                ans |= backtrack(idx, idx+1, s, newString, startingDict, dict, visit);
                newString.pop_back();
            } 
        
        }
        
        return visit[curStrBeg] = ans;
        
        
    }
};