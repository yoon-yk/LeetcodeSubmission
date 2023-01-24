class UnionFind {
private : 
    vector<int> parent, rank;
    
public : 
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) return;
        else if (rank[xset] < rank[yset]) parent[xset] = yset;
        else {
            parent[yset] = xset;
            if (rank[xset] == rank[yset]) ++rank[xset];
        } 
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adjList(n);
        for (auto & e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        map<int, vector<int>> valuesToNodes;
        for (int node = 0; node<n; ++node) {
            valuesToNodes[vals[node]].push_back(node);
        }
        
        UnionFind dsu(n);
        int goodPaths = 0;
        
        for (auto & [v, nodes] : valuesToNodes) {
            for (int & node : nodes) {
                for (int & nei : adjList[node]) {
                    if (vals[node] >= vals[nei]) {
                        dsu.union_set(node, nei);
                    }
                }
            }
            
            unordered_map<int, int> group;
            for (int & u : nodes) {
                ++group[dsu.find(u)];
            }
            
            for (auto & [_, sz] : group) {
                goodPaths += (sz * (sz+1)) / 2;
            }
        }
        return goodPaths;
    }
};