class Trie {
public :
    Trie* next[26] = {};
    int wordIdx;
    bool isWord;
    bool isInserted;
    
    Trie() {
        isWord = false;
        isInserted = false;
    }
    
    void insertWord(int idx, string &word) {
        int c;
        Trie* curNode = this;
        for (int i=0; i<word.size(); i++) {
            c = word[i]-'a';
            if (!curNode->next[c]) curNode->next[c] = new Trie();
            curNode = curNode->next[c];
        }
        curNode->isWord = true;
        curNode->wordIdx = idx;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 필요한 DS - Trie, ans 
        
        vector<string> ans;
        Trie* root = new Trie();
        
        // Trie에 주어진 Words 다 추가해놓기 
        for (int i=0; i<words.size(); i++) {
            root->insertWord(i, words[i]);
        }
        
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        // backtracking 하면서 trie에 존재하는지 확인하기
        string curStr;
        Trie* curNode;
        int n=board.size(), m = board[0].size();
        for (int r=0; r<n; r++) {
            for (int c=0; c<m; c++) {
                if (!root->next[board[r][c]-'a']) continue;
                curNode = root->next[board[r][c]-'a'];
                visited[r][c] = true;
                explore (board, visited, words, r, c, curNode, ans);
                visited[r][c] = false;
            }
        }
        
        return ans;
    }
    
    vector<int> dir = {-1, 0, 1, 0, -1};
    
    bool isRangeValid(vector<vector<char>>& board, int r, int c){
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return false;
        return true;
    }
    
    void explore (vector<vector<char>>& board, vector<vector<bool>>& visited, vector<string>& words, int r, int c, Trie* curNode, vector<string>& ans) {
    
        Trie* root = curNode;
        if (root->isWord && !root->isInserted) {
            ans.push_back(words[root->wordIdx]);
            root->isInserted = true;
        }
            
        int newR, newC;
        Trie* nextRoot;
        for (int d=0; d<4; d++) {
            newR = r+dir[d], newC = c+dir[d+1];
            if (!isRangeValid(board, newR, newC)) continue;
            nextRoot = root->next[board[newR][newC]-'a'];
            if (!visited[newR][newC] && nextRoot) {
                visited[newR][newC] = true;
                explore (board, visited, words, newR, newC, nextRoot, ans);
                visited[newR][newC] = false;
            }
        }
        
    }
};