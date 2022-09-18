class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> keys = 
        {{}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        
        deque<string> q;
        q.push_back("");
        backtrack(0, digits, keys, q);
        
        vector<string> ans;
        
        while (!q.empty() && q.front()!= "") {
            ans.push_back(q.front());
            q.pop_front();
        }
        
        return ans;
        
    }
    
    void backtrack(int idx, string& digits, vector<vector<char>>& keys, deque<string>& q) {
        
        if (idx == digits.size()) {
            return;
        }
        
        int digit = digits[idx] - '0';
        
        int size = q.size();
        while (size--) {
            string cur = q.front(); q.pop_front();
            for (int i=0; i<keys[digit].size(); i++) {
                q.push_back(cur+keys[digit][i]);
            }
        }
        
        backtrack(idx+1, digits, keys, q);
        
    }
};