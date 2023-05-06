class UnionAndFind {
public:
    vector<int> parent;
    vector<int> size;
    int compN;
    
    UnionAndFind(int n){
        for (int i = 0; i <= n; i++) {
            parent.push_back(i);
            size.push_back(1);
        }
        compN = n;
    }
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    bool connectAndCheckIfConnected(int a, int b) {
        int p1 = find(a), p2 = find(b);
        if (p1 == p2) return true;
        if (size[p1] < size[p2]) {
            parent[p1] = p2;
            size[p2] += size[p1];
        } else {
            parent[p2] = p1;
            size[p1] += size[p2];
        }
        --compN;
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        sort(edges.begin(), edges.end(), [](auto &a, auto &b){
            return a[0] > b[0];
        });
        
        UnionAndFind * alice = new UnionAndFind(n), * bob = new UnionAndFind(n);
        
        int answer = 0;
        int i = 0;
        for (; i< edges.size() && edges[i][0] == 3; ++i){
            if (alice->connectAndCheckIfConnected(edges[i][1], edges[i][2]) 
                | bob->connectAndCheckIfConnected(edges[i][1], edges[i][2])) ++answer;
        }
        
        for (; i< edges.size(); ++i) {
            if (edges[i][0] == 1) {
                answer += alice->connectAndCheckIfConnected(edges[i][1], edges[i][2]);
            }
            if (edges[i][0] == 2) {
                answer += bob->connectAndCheckIfConnected(edges[i][1], edges[i][2]);
            }
        }
        
        if (alice->compN != 1 || bob->compN != 1) return -1;
        
        return answer;
    }
};