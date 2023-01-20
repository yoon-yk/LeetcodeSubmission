class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        int n = s.size();
        unordered_set<string> seen;
        vector<int> left(26, 0), right(26, 0);
        for (int i=n-1; i>=0; --i) 
            ++right[s[i]-'a'];
        
        for (int i=0; i<n; ++i) { // i = center
            string ss;
            ss+=s[i];
            --right[s[i]-'a'];
            for (int k=0; k<26; ++k) {
                if (left[k] > 0 && right[k] > 0)  {
                    seen.insert(ss+(char)(k+'a'));
                }
            }
            ++left[s[i]-'a'];
        }
        
        // for (auto & str : seen)
        //     cout << str << endl;
        
        return seen.size();
    }
};