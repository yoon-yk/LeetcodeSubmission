class Trie {
private:
    Trie* next[26] = {};
    bool isWord;
public :
    Trie(){
        isWord = false;
    }
    
    void insertWord (string word) {
        Trie* curNode = this;
        int c;
        for (char & ch : word) {
            c = ch-'a';
            if (!curNode->next[c]) 
                curNode->next[c] = new Trie();
            curNode = curNode->next[c];
        }
        curNode->isWord = true;
    }
    
    bool search(Trie* root, string& word, int idx) {
        Trie* curNode = root;
        int c;
        bool ans = false;
        
        for (int i=idx; i<word.size(); i++) {
            char ch = word[i];
            
            if (ch == '.') {
                for (int j=0; !ans && j<26; j++) {
                    if (curNode->next[j]) {
                        ans |= search(curNode->next[j], word, i+1);
                    }
                }
                return ans;
            } else {
                c = ch-'a';
                if (!curNode->next[c]) return false;
                curNode = curNode->next[c];                
            }
        }
        return curNode->isWord;
    }
    
    
    bool searchWord (string word) {
        return search(this, word, 0);
    }
};

class WordDictionary {
private:
    Trie* root;
public:
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        root->insertWord(word);
    }
    
    bool search(string word) {
        return root->searchWord(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */