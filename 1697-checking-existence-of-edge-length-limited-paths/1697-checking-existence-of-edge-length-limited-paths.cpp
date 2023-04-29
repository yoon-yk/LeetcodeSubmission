class Solution {
public:
    // parent 
    vector<int> parent;
    
    // unionn
    void unionn(int a, int b) {
        int p1 = find(a), p2 = find(b);
        if (p1 == p2) return;
        parent[p1] = p2;
    }
    
    // find 
    int find(int a) {
        if (a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
        
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        // add index to edgeList
        int i = 0;
        for (auto & query : queries) {
            query.push_back(i++);
        }
        
        // sort edgeList by its dist 
        sort(edgeList.begin(), edgeList.end(),[](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });

        // sort queries by its min limit
        sort(queries.begin(), queries.end(),[](vector<int>& a, vector<int>& b){
            return a[2] < b[2];
        });
        
        vector<bool> ans(queries.size());
        i = 0;
        for (auto & query : queries) {
            int minlim = query[2];
            while (i < edgeList.size() && edgeList[i][2] < minlim) {
                unionn(edgeList[i][0], edgeList[i][1]);
                ++i;
            }
            ans[query[3]] = (find(query[0]) == find(query[1]));
        }
        return ans;
    }
};