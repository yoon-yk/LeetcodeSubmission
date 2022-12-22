class TrieNode{
public:
    int value;
    unordered_map<string, TrieNode*> children;
    
    TrieNode() {
        value = -1;
    };
};

class FileSystem {
public:
    TrieNode* root = new TrieNode();
    
    FileSystem() {}
    
    bool create(TrieNode* curPath, stringstream& path, int value) {
        string name;
        if (getline(path, name, '/') && path.eof()) {
            if (curPath->children.count(name)) return false;
            curPath->children[name] = new TrieNode();
            curPath->children[name]->value = value;
            return true;
        }
        if (!curPath->children.count(name)) return false;
        return create(curPath->children[name], path, value);
    }
    
    bool createPath(string path, int value) {
        string tmp;
        stringstream s(path);
        getline(s, tmp, '/');
        return create(root, s, value);
    }
    
    int getPath(TrieNode* curPath, stringstream& path) {
        string name;
        if (getline(path, name, '/') && path.eof()) {
            if (!curPath->children.count(name)) return -1;
            return curPath->children[name]->value;
        }

        if (!curPath->children.count(name)) return -1;
        return getPath(curPath->children[name], path);
    }
    
    int get(string path) {
        string tmp;
        stringstream s(path);
        getline(s, tmp, '/');
        return getPath(root, s);
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */