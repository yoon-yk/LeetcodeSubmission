class Solution {
public:
    vector<int> parent, size;

    int findd(int v) {
        if (parent[v] == v) return v;
        return parent[v] = findd(parent[v]);
    }
    
    void unionn(int v1, int v2) {
        int p1 = findd(v1), p2 = findd(v2);
        if (p1 == p2) return;
        if (size[p2] > size[p1]) {
            parent[p1] = p2;   
            size[p2] += size[p1];
        } else {
            parent[p2] = p1;   
            size[p1] += size[p2];
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
        
        for (auto & p : pairs) {
            unionn(p[0], p[1]);
        }
        
        unordered_map<int, set<int>> mp;
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> cmp;
        for (int i=0, grp; i<n; ++i) {
            grp = findd(i);
            mp[grp].insert(i);
            cmp[grp].push(s[i]);
        }
        
        for (auto &[idx, set] : mp) {
            auto pq = cmp[idx];
            for (auto & id : set) {
                s[id] = pq.top(); pq.pop();
            }
        }
        
        return s;
    }
};