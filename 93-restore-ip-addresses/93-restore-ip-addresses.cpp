class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curStr = "";
        backtrack(s, 0, 0, 0, 3, curStr, ans);
        
        return ans;
    }
    
    void backtrack(string &s, int globalIdx, int localIdx, int localNum,  int totalWall, string& curStr, vector<string>& ans) {
        
        if (localNum > 255) return;
        
        // base case
        if (globalIdx == s.size() && totalWall == 0) {
            ans.emplace_back(curStr);
            return;
        }

        // include '.'
        if (globalIdx > 0 && totalWall > 0) {
            curStr.push_back('.');
            curStr.push_back(s[globalIdx]);
            backtrack(s, globalIdx+1, 1, s[globalIdx]-'0', totalWall-1, curStr, ans);
            curStr.pop_back();            
            curStr.pop_back();  
        }
            
        // exclude (keep going -- only if it can)
        if (localIdx < 3 && !(localIdx == 1 && s[globalIdx-1]== '0')) {
            curStr.push_back(s[globalIdx]);
            backtrack(s, globalIdx+1, localIdx+1, localNum* 10 + (s[globalIdx]-'0'), totalWall, curStr, ans);
            curStr.pop_back();      
        }
        
    }
};