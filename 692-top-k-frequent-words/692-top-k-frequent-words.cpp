class Solution {
public:
    int k;
    struct TrieNode{
        bool isWord = false;
        TrieNode* children[26];
        
        TrieNode() {
            for (int i=0; i<26; i++)
                this->children[i] = nullptr;
        }
    };
    
    void addWord (TrieNode* rt, const string& word) {
        TrieNode* cur = rt;
        for (auto & c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr)
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }
    
    void getWords (TrieNode*& cur, string& prefix, vector<string>& ans) {

        if (k == 0)
            return;
        
        if (cur->isWord) {
            ans.push_back(prefix);
            k--;
        }
        
        for (int i=0; i<26; i++) {
            if (cur->children[i] != nullptr) {
                prefix += i + 'a';
                getWords(cur->children[i], prefix, ans);
                prefix.pop_back();
            }
        }
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        this->k = k;
        unordered_map<string, int> hashM;
        for (auto& w : words) hashM[w]++;
        
        vector<string> ans;
        TrieNode* root[n+1];
        for (int i=0; i<=n; i++)
            root[i] = new TrieNode();
        
        for (auto & h : hashM) 
            addWord (root[h.second], h.first);
        
        string prefix = "";
        for (int freq=n; freq>=0; freq--)
            getWords(root[freq], prefix, ans);
        
        return ans;
        
    }
};