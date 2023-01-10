class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<vector<char>> rows(numRows+1);
        int curR = 0;
        bool inc = true;
        for (int i=0; i<s.size(); ++i) {
            rows[curR].push_back(s[i]);
            if (curR == numRows-1) inc = false;
            else if (curR == 0) inc = true;
            if (inc) ++curR;
            else --curR;
        }
        
        string ans;
        for (int i=0; i<numRows; ++i) {
            for (auto & c : rows[i]) {
                ans += c;
            }
        }
        
        return ans;
    }
};