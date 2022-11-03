class TrieNode {
public:
    vector<TrieNode*> links;
    int R = 26;
    bool isWord;

    TrieNode() {
        links.resize(R, NULL);
        isWord = false;
    }
    
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    
    TrieNode* get(char ch) {
        return links[ch-'a'];
    }
    
    void put (char ch, TrieNode* node) {
        links[ch-'a'] = node;
    }

};

class Trie {
private :
    TrieNode* root;
    
public :
    Trie () {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i=0; i< word.size(); i++) {
            char curCh = word[i];
            if (!node->containsKey(curCh))
                node->put(curCh, new TrieNode());
            node = node->get(curCh);
        }
        node->isWord = true;
    }
    
    TrieNode* searchPrefix(string word) {
        TrieNode *node = root;
        for (int i=0; i<word.size(); i++) {
            char curCh = word[i];
            if (node->containsKey(curCh))
                node = node->get(curCh);
            else return NULL;
        }
        return node;
    }
    
    bool search(string word) {
        TrieNode *node = searchPrefix(word);
        return node && node->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = searchPrefix(prefix);
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */