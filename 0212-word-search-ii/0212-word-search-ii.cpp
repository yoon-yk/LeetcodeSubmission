class Trie {
public :
    Trie* next[26] = {};
    bool isWord;
    bool isInserted;
    
    Trie() {
        isWord = false;
        isInserted = false;
    }
    
    void insertWord(string &word) {
        int c;
        Trie* curNode = this;
        for (int i=0; i<word.size(); i++) {
            c = word[i]-'a';
            if (!curNode->next[c]) curNode->next[c] = new Trie();
            curNode = curNode->next[c];
        }
        curNode->isWord = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // 필요한 DS - Trie, ans 
        
        vector<string> ans;
        Trie* root = new Trie();
        
        // Trie에 주어진 Words 다 추가해놓기 
        for (string& word : words) {
            root->insertWord(word);
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
                curStr += board[r][c];
                visited[r][c] = true;
                explore (board, visited, r, c, curNode, curStr, ans);
                visited[r][c] = false;
                curStr.pop_back();
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
    
    void explore (vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c, Trie* curNode, string& curStr, vector<string>& ans) {
    
        Trie* root = curNode;
        if (root->isWord && !root->isInserted) {
            ans.push_back(curStr);
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
                curStr += board[newR][newC];
                explore (board, visited, newR, newC, nextRoot, curStr, ans);
                curStr.pop_back();
                visited[newR][newC] = false;
            }
        }
        
    }
};