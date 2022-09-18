class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int globalIdx = 0, localIdx = 0, localNum = 0, totalWall = 3;
        string curStr = "";
        backtrack(s, globalIdx, localIdx, localNum, curStr, totalWall, ans);
        
        return ans;
    }
    
    void backtrack(string &s, int globalIdx, int localIdx, int localNum, string& curStr, int totalWall, vector<string>& ans) {
        
        if (localNum > 255) return;
        
        // base case
        if (globalIdx == s.size() && totalWall == 0) {
            ans.push_back(curStr);
            return;
        }

        // include '.'
        if (globalIdx > 0 && totalWall > 0) {
            curStr += '.';
            curStr += s[globalIdx];
            backtrack(s, globalIdx+1, 1, s[globalIdx]-'0', curStr, totalWall-1, ans);
            curStr.pop_back();            
            curStr.pop_back();  
        }
            
        // exclude (keep going -- only if it can)
        if (localIdx < 3 && !(localIdx == 1 && s[globalIdx-1]== '0')) {
            curStr += s[globalIdx];
            backtrack(s, globalIdx+1, localIdx+1, localNum* 10 + (s[globalIdx]-'0'), curStr, totalWall, ans);
            curStr.pop_back();      
        }
        
    }
};