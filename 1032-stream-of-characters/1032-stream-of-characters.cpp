class Trie {
public :
    bool isWord;
    vector<Trie*> children;
    
    Trie () {
        isWord = false;
        children.resize(26, NULL);
    }
};

class StreamChecker {
public:
    Trie* root;
    deque<Trie*> dq;
    
    void insertWord(Trie* root, string& s) {
        Trie* cur = root;
        for (int i=0; i<s.size(); ++i) {
            char & c = s[i];
            if (cur->children[c-'a'] == NULL)
                cur->children[c-'a'] = new Trie();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }
    
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for (auto& word : words) 
            insertWord(root, word);
    }
    
    bool findWord(Trie*& trieRoot, char& letter) {
        trieRoot = trieRoot->children[letter-'a'];
        return (trieRoot != NULL && trieRoot->isWord);
    }
    
    bool query(char letter) {
        dq.push_back(root);
        int size = dq.size();
        bool ans = false;
        while (size--) {
            auto ptr = dq.front(); dq.pop_front();
            if (findWord(ptr, letter)) ans = true;
            if (ptr != NULL) dq.push_back(ptr);
        }
        return ans;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */