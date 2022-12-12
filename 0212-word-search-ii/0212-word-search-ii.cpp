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
        vector<string> ans;
        string curStr;

        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                dfs(board, i, j, curStr, root, ans);
            }
        }
        
        return ans;
    }
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    void dfs(vector<vector<char>>& board, int i, int j, string& curStr, TrieNode* cur, vector<string>& ans) {
        
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] == '#' || cur->children[board[i][j]-'a'] == NULL) return;
        
        char curCh = board[i][j];
        cur = cur->children[curCh-'a'];
        curStr.push_back(curCh);
        board[i][j] = '#';

        if (cur->isWord) ans.push_back(curStr);
        cur->isWord = false;
        
        for (int d=0; d<4; d++) 
            dfs(board, i + dir[d], j+dir[d+1], curStr, cur, ans);

        board[i][j] = curCh;
        curStr.pop_back();
    }
};