class TrieNode {
public: 
    bool isWord;
    vector<TrieNode*> children;

    TrieNode() {
        isWord = false;
        children.resize(26, NULL);
    };
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    
    void insertWord(string& word) {
        TrieNode* cur = root;
        for (auto & c : word) {
            if (cur->children[c-'a'] == NULL)
                cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }    
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (auto & w : words) insertWord(w);
        
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<string> ans;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                string curStr;
                dfs(board, visited, i, j, curStr, root, ans);
            }
        }
        
        return ans;
    }
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& curStr, TrieNode* cur, vector<string>& ans) {
        
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j] || cur->children[board[i][j]-'a'] == NULL) return;
        
        cur = cur->children[board[i][j]-'a'];
        curStr.push_back(board[i][j]);

        if (cur->isWord) ans.push_back(curStr);
        cur->isWord = false;
        visited[i][j] = true;
        
        for (int d=0; d<4; d++) 
            dfs(board, visited, i + dir[d], j+dir[d+1], curStr, cur, ans);

        
        visited[i][j] = false;
        curStr.pop_back();
    }
};