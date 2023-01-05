class TrieNode {
public:
    bool isWord;
    vector<TrieNode*> children;
    
    TrieNode() {
        isWord = false;
        children.resize(26, NULL);
    }
};

class Solution {
public:
    void insertWord(TrieNode* root, string &s) {
        for (int i=0; i<s.size(); ++i) {
            if (root->children[s[i]-'a'] == NULL)
                root->children[s[i]-'a'] = new TrieNode();
            root = root->children[s[i]-'a'];
        }
        root->isWord = true;
    }

    
    void getWords(TrieNode* root, string &curStr, 
                  vector<string>& ans) {
        
        if (root->isWord) ans.push_back(curStr);
        for (int i=0; i<26 && ans.size() < 3; ++i) {
            if (!root->children[i]) continue;
            curStr.push_back(i+'a');
            getWords(root->children[i], curStr, ans);
            curStr.pop_back();
        }
    }

    
    TrieNode* root;
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new TrieNode();
        vector<vector<string>> ans(searchWord.size());
        
        for (auto& w : products) insertWord(root, w);

        TrieNode* cur = root;
        string curStr;
        for (int i=0; i<searchWord.size(); ++i) {
            char& c = searchWord[i];
            curStr.push_back(c);    
            cur = cur->children[c-'a'];
            if (!cur) break;
            getWords(cur, curStr, ans[i]);           
        }
        
        return ans;
    }
};