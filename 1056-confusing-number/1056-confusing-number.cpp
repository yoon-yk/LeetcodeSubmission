class Solution {
public:
    unordered_set<char> invalid = {'2', '3', '4', '5', '7'};
    unordered_map<char, char> pairs = {
        {'0', '0'}, 
        {'1', '1'},
        {'6', '9'},
        {'8', '8'},
        {'9', '6'}, 
    };

    bool confusingNumber(int n) {
        bool different = false;
        string s = to_string(n);
        
        int ridx;
        for (int i=0; i<((s.size()+1) >> 1); ++i) {
            ridx = s.size()-1-i;
            if (invalid.count(s[i]) || invalid.count(s[ridx]))
                return false;   
            if (s[ridx] != pairs[s[i]]) 
                different = true;
        }
        return different;
    }
};