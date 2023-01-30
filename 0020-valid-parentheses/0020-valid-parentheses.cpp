class Solution {
public:
    unordered_set<char> opens = {'(', '[', '{'};
    unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    bool isValid(string s) {
        vector<char> st;
        for (auto & ch : s) {
            if (opens.count(ch)) st.push_back(ch);
            else {
                if (st.empty()) return false;
                if (st.back() == pairs[ch]) st.pop_back();
                else return false;
            }
        }
        return (st.empty());
    }
};