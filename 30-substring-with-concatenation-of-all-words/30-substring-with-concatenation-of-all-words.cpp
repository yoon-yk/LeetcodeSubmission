class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> counts;
        unordered_map<string, int> seen;

        for (string word : words)
            counts[word]++;
        
        int n = s.length(), size = words.size(), len = words[0].length();
        vector<int> ans;
        
        for (int startIdx = 0; startIdx < n - size * len + 1; startIdx++) {
            seen.clear();
            int j = 0;
            for (; j < size; j++) {
                string word = s.substr(startIdx + j * len, len);
                if (counts.count(word)) {
                    seen[word]++;
                    if (seen[word] > counts[word])
                        break;
                }
                else break;
            }
            if (j == size) ans.push_back(startIdx);
        }
        return ans;        
    }
};
