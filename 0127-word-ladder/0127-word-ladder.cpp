class Solution {
public:
    
    void findNeighbor(int curIdx, vector<string>& wordList, unordered_map<string, int>& dict, unordered_set<int>& visited, vector<int>& ans) {
        
            string word = wordList[curIdx];
            for (int i=0; i<word.size(); i++){
                char curCh = word[i];
                for (int k=0; k<26; k++) {
                    if (curCh == k+'a') continue;
                    word[i] = k+'a';
                    if (dict.count(word) && !visited.count(dict[word])) {
                        ans.push_back(dict[word]);
                    }
                }
                word[i] = curCh;
            }
    }
    
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
        if (!dict.count(beginWord)) {
            wordList.push_back(beginWord);
            dict[beginWord] = idx++;
        }
        
        // vector<vector<int>> adjList(dict.size());
        
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
                
                vector<int> adjList;
                findNeighbor(cur, wordList, dict, visited, adjList);
                
                for (auto & nei : adjList) {
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