class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len = digits.length();
        if (len == 0) return res;
        
        unordered_map <int, vector<string>> keyboard;
        keyboard[2] = {"a", "b", "c"};
        keyboard[3] = {"d", "e", "f"};
        keyboard[4] = {"g", "h", "i"};
        keyboard[5] = {"j", "k", "l"};
        keyboard[6] = {"m", "n", "o"};
        keyboard[7] = {"p", "q", "r", "s"};
        keyboard[8] = {"t", "u", "v"};
        keyboard[9] = {"w", "x", "y", "z"};

        if (len == 1)
            return keyboard[digits[0]-'0'];
        
        queue<string> q; 
        //q.push("");
        
        // index 0 chars 모두 넣기
        for (auto ch : keyboard[digits[0]-'0']) {
            q.push(ch);
        }
        
        int i = 1;
        while (i < len){
            for (int j = q.size(); j > 0; j--) {
                string curCh = q.front();
                q.pop();
                
                for (auto ch : keyboard[digits[i]-'0'])
                    q.push(curCh+ch);
            }        
            i++;
        }
        
        while(!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};