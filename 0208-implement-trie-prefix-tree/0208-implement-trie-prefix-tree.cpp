class TrieNode {
public:
    vector<TrieNode*> ch;
    bool isWord;
    
    TrieNode() {
        ch.resize(26, NULL);
        isWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        
        int curC;
        for (int i=0; i<word.size(); i++) {
            curC = word[i]-'a';
            if (cur->ch[curC] == NULL)
                cur->ch[curC] = new TrieNode();
            cur = cur->ch[curC];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        int curC;
        for (int i=0; i<word.size(); i++) {
            curC = word[i]-'a';
            if (cur->ch[curC] == NULL) return false;
            cur = cur->ch[curC];
        }
        return (cur->isWord);    
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        int curC;
        for (int i=0; i<prefix.size(); i++) {
            curC = prefix[i]-'a';
            if (cur->ch[curC] == NULL) return false;
            cur = cur->ch[curC];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */