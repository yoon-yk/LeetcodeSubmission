class Solution {
public:
    
    void slidingWindow(string s, int startIdx, vector<string>& words, unordered_map<string, int>& counts, vector<int> &ans) {
        int j = 0;
        int len = words[0].length();
        int num = words.size();
        unordered_map<string, int> seen;
        for (; j < num; j++) {
            string word = s.substr(startIdx + j * len, len);
            if (counts.count(word)) {
                seen[word]++;
                if (seen[word] > counts[word])
                    break;
            }
            else break;
        }
        if (j == num) ans.push_back(startIdx);
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        for (string word : words)
            counts[word]++;
        
        int n = s.length(), num = words.size(), len = words[0].length();
        vector<int> ans;
        
        for (int i = 0; i < n - num * len + 1; i++) {
            slidingWindow(s, i, words, counts, ans);
        }
        return ans;        
    }
};
