class Solution {
public:
    int longestStrChain(vector<string>& words) {
        /*
        a ba bca bdca 
        b ba bda bdca
        */
        int n = words.size();
        unordered_map<string, int> map;
        for (int i=0; i<n; i++) map[words[i]] = i;
        
        vector<vector<int>> adjList(n);
        
        for (int i=0; i<n; i++) {
            string first = "";
            string second = words[i];
            for (int j=0; j<=words[i].size(); j++) {
                string newWord = first + '0' + second;
                for (int k=0; k<26; k++) {
                    newWord[j] = k+'a';
                    if (map.count(newWord))
                        adjList[i].push_back(map[newWord]);
                }
                if (second.size() > 0) {
                    first.push_back(second[0]);
                    second = second.substr(1);
                }
            }
        }
        
        int len = 0;
        vector<int> memo(n, -1);
        for (int i=0; i<n; i++)
            len = max(len, dfs(i, adjList, memo));
        
        return len;
    }
    
    int dfs(int curIdx, vector<vector<int>>& adjList, vector<int>& memo) {
        
        if (memo[curIdx]!= -1)
            return memo[curIdx];
        
        int maxLen = 1;
        
        for (int & nei : adjList[curIdx]) 
            maxLen = max(maxLen, dfs(nei, adjList, memo) + 1);
        
        return memo[curIdx] = maxLen;
    }
};