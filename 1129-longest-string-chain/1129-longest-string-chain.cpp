class Solution {
public:
    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.size() < b.size();
        });

        int ans = 0;
        unordered_map<string, int> longest;
        for (int i=0; i<words.size(); ++i) {
            string & w = words[i];
            int chLen = 1;

            for (int j=0; j<w.size(); ++j) {
                string p = w.substr(0, j) + w.substr(j+1, w.size()-j-1);
                if (longest.count(p)) chLen = max(longest[p]+1, chLen);
            }
            longest[w] = chLen;
            ans = max(ans, chLen);
        }

        return ans;
    }
};