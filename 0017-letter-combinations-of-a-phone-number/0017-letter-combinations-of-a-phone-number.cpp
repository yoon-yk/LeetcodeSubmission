class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> chs = {
            {}, {},
            {'a', 'b', 'c'}, // 2
            {'d', 'e', 'f'}, // 3
            {'g', 'h', 'i'}, // 4
            {'j', 'k', 'l'}, // 5
            {'m', 'n', 'o'}, // 6
            {'p', 'q', 'r', 's'}, // 7
            {'t', 'u', 'v'}, // 8
            {'w', 'x', 'y', 'z'}, // 9
        };
        
        if (digits.size() == 0) return {};
        string curStr;
        vector<string> ans;
        backtrack(digits, 0, chs, curStr, ans);
        
        return ans;
    }
    
    void backtrack(string& digits, int idx, vector<vector<char>>& chs,
                   string& curStr, vector<string>& ans) {
        
        if (idx == digits.size()) {
            ans.push_back(curStr);
            return;
        }
        
        int curD = digits[idx]-'0';
        for (int i=0; i<chs[curD].size(); i++) {
            curStr.push_back(chs[curD][i]);
            backtrack(digits, idx+1, chs,curStr, ans);
            curStr.pop_back();
        }
    }
};