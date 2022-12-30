class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // sort 
        sort(words.begin(), words.end(), [](string& a, string& b) {
           return a.size() < b.size(); 
        });
        
        // for (auto & w : words) cout << w << endl;
        // if chain - put into adjList
        
        int n = words.size();
        unordered_map<string, int> mp;
        vector<vector<int>> adjList(n);
        for (int i=0; i<words.size(); ++i) {
            for (int j=0; j<words[i].size(); ++j) {
                string next = words[i].substr(0, j) + words[i].substr(j+1);
                if (mp.count(next))
                    adjList[i].push_back(mp[next]);
            }
            mp[words[i]] = i;
        }
        int ans = 0;
        
        vector<int> dp(n, -1);
        for (int i=0; i<n; ++i)
            ans = max(ans, dfs(i, adjList, dp));
        
        // dfs + dp
        return ans;
    }
    
    int dfs(int cur, vector<vector<int>>& adjList, vector<int>& dp) {
        
        if (dp[cur]!=-1) return dp[cur];
        
        int ans = 1;
        for (auto & nei : adjList[cur])
            ans = max(ans, dfs(nei, adjList, dp)+1);
        
        return dp[cur] = ans;
    }
};