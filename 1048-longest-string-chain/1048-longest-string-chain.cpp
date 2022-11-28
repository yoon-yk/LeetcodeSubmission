class TrieNode {
public:
    int idx;
    vector<TrieNode*> ch;
    
    TrieNode() {
        idx = -1;
        ch.resize(26);
    }
};

class Solution {
public:
    void insert(TrieNode* root, string& w, int curIdx) {
        TrieNode *cur = root;
        for (int i=0; i<w.size(); i++) {
            int curCh = w[i] - 'a';
            if (cur->ch[curCh] == NULL)
                cur->ch[curCh] = new TrieNode();
            cur = cur->ch[curCh];
        }
        cur->idx = curIdx;
    }
    
    void findPredecessor (TrieNode* root, string& w, int startIdx, bool skipped, int curWordIdx, int len, vector<vector<int>>& adjList) {
        TrieNode* cur = root;
        for (int i=startIdx; i<=w.size(); i++) {
            if (!skipped) {
                for (int k=0; k<26; k++) {
                    if (cur->ch[k] == NULL) continue; 
                    findPredecessor (cur->ch[k], w, i, true, curWordIdx, len-1, adjList);
                }
            } 
            if (i < w.size()) {
                int curCh = w[i] - 'a';
                if (cur->ch[curCh] == NULL) return;
                cur = cur->ch[curCh];
                len --; 
            }

        }
        if (len == 0 && cur->idx > -1 && cur->idx != curWordIdx)
            adjList[curWordIdx].push_back(cur->idx);        
    }
    
    int longestStrChain(vector<string>& words) {
        /*
        a ba bca bdca 
        b ba bda bdca
        */
        int n = words.size();
        
        TrieNode * root = new TrieNode();
        for (int i=0; i<n; i++) insert(root, words[i], i);
        
        vector<vector<int>> adjList(n);
        for (int i=0; i<n; i++)
            findPredecessor(root, words[i], 0, false, i, words[i].size()+1, adjList);
        
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