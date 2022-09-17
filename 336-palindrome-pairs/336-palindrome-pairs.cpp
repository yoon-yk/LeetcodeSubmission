struct TrieNode {
    TrieNode *next[26] = {};
    int index = -1;
    vector<int> palindromeIndexes;
};

class Solution {
public:
    
    void addToTrie(int wordIdx, string& s, TrieNode*& node) {
       for (int j = s.size()-1; j>=0; --j) {
           if (isPalindrome(s, 0, j)) 
                node->palindromeIndexes.push_back(wordIdx);
         
           int c = s[j] - 'a';
           if (!node->next[c]) 
               node->next[c] = new TrieNode();
           node = node->next[c];
       }
    
       node->index = wordIdx;
       node->palindromeIndexes.push_back(wordIdx);
    }
    
    void getWord(int wordIdx, string& s, TrieNode*& node, vector<vector<int>>& ans) {
        
        for (int j=0; j<s.size() && node; j++) {
            // case 3
            if (node->index != -1 && node->index != wordIdx && isPalindrome(s, j, s.size()-1))
                ans.push_back({wordIdx, node->index}); 
            node = node->next[s[j] - 'a'];
        }
        if (!node) return;

        // case 2
        for (int j : node->palindromeIndexes) 
            if (wordIdx!=j) ans.push_back({wordIdx, j});
    }

    
    bool isPalindrome (string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        TrieNode* root = new TrieNode;

        TrieNode* node;
        for (int i=0; i<n; i++) {
            auto s = words[i];
            node = root;
            addToTrie(i, s, node);
        }
        
        vector<vector<int>> ans;
        for (int i=0; i<n; i++) {
            auto s = words[i];
            node = root;
            getWord(i, s, node, ans);
        }
        return ans;
    }
};  