class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*
        
        beginWord = "hit", endWord = "cog", 
        wordList = ["hot","dot","dog","lot","log","cog"]
        
        "hit"-> "hot"-> "dot" -> "dog" -> "cog"
        
        // shortest transformation --> BFS?
        
        */
        int idx = 0;
        unordered_map<string, int> dict;
        for (auto & word : wordList) {
            dict[word] = idx++;
        }
        if (!dict.count(endWord)) return 0;
        if (!dict.count(beginWord)) dict[beginWord] = idx++;
        
        vector<vector<int>> adjList(dict.size());
        
        
        for (auto & [word, idx] : dict) {
            string curWord = word;
            for (int i=0; i<word.size(); i++){
                char curCh = word[i];
                for (int k=0; k<26; k++) {
                    if (curCh == k+'a') continue;
                    curWord[i] = k+'a';
                    if (dict.count(curWord)) {
                        adjList[idx].push_back(dict[curWord]);
                    }
                }
                curWord[i] = curCh;
            }
        }
    
        unordered_set<int> visited;
        visited.insert(dict[beginWord]);
        queue<int> Q;
        Q.push(dict[beginWord]);
        
        int targetIdx = dict[endWord];
        int level = 1, size;
        while (!Q.empty()) {
            size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                
                for (auto & nei : adjList[cur]) {
                    if (visited.count(nei)) continue;
                    if (nei == targetIdx) return level+1;
                    Q.push(nei);
                    visited.insert(nei);
                }
            }
            level++;
        }
        
        // int ans = dfs (dict[endWord], dict[beginWord], visited, adjList) + 1;
        
        return 0;
    }
    
    
    int dfs (int end, int cur, unordered_set<int>& visited, vector<vector<int>>& adjList) {
        
        if (cur == end) 
            return 0;
        
        int ans = 5005, curLen;
        for (auto& nei : adjList[cur]) {
            if (visited.count(nei)) continue;
            visited.insert(nei);
            curLen = dfs(end, nei, visited, adjList);
            if (curLen < ans)
                ans = curLen + 1;
            visited.erase(nei);
        }
        
        return ans;
    }
    
};