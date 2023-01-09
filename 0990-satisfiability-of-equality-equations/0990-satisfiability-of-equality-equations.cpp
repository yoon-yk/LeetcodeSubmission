class Solution {
public:
    vector<int> parent;
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    
    void unionn(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return;
        parent[p1] = parent[p2];
    }
    
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26, -1);
        iota(parent.begin(), parent.end(), 0);
        
        for (auto & eq : equations) {
            if (eq[1] == '=') {
                unionn(eq[0]-'a', eq[3]-'a');
            }
        }
        
        
        for (auto & eq : equations) {
            if (eq[1] == '!') {
                if (find(eq[0]-'a') == find(eq[3]-'a'))
                    return false;
            }
        }
        
        return true;
    }
};