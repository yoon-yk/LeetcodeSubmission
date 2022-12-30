class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort 
        sort(words.begin(), words.end(), [](string& a, string& b) {
           return a.size() < b.size(); 
        });
        
        // for (auto & w : words) cout << w << endl;
        // if chain - put into adjList
        
        int n = words.size(), ans;
        unordered_map<string, int> mp;
        for (int i=0; i<words.size(); ++i) {
            mp[words[i]] = 1;
            for (int j=0; j<words[i].size(); ++j) {
                string next = words[i].substr(0, j) + words[i].substr(j+1);
                if (mp.count(next))
                    mp[words[i]] = max(mp[words[i]], mp[next]+1);
            }
            ans = max(ans, mp[words[i]]);
        }

        // dfs + dp
        return ans;
    }
};