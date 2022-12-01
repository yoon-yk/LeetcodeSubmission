class TrieNode {
public :
    vector<TrieNode*> ch;
    bool isWord;
    
    TrieNode() {
        ch.resize(26, NULL);
        isWord = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    
    WordDictionary() {        
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
        return search(root, word, 0);
    }
    
    bool search(TrieNode* rt, string& word, int sIdx) {
        TrieNode* cur = rt;
        int curC;
        for (int i=sIdx; i<word.size(); i++) {
            if (word[i] == '.') {
                for (int j=0; j<26; j++) {
                    if (cur->ch[j] == NULL) continue;
                    if (search(cur->ch[j], word, i+1)) 
                        return true;
                }
                return false;    //***********
            } else {
                curC = word[i]-'a';
                if (cur->ch[curC] == NULL) return false;
                cur = cur->ch[curC];  
            }
        }
        return cur && cur->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */