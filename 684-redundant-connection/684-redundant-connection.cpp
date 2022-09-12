/* LeetCode: tktripathy */
class Solution {
public:
    /*
     * Find the subset a vertex belongs to.
     */
    int find(vector<int> &ss, int x) {
        if (ss[x] == x) return x;
        return ss[x] = find(ss, ss[x]);
    }
    
    /*
     * Unionize two subsets. 
     */
    void _union(vector<int> &ss, int x, int y) {
        int xp = find(ss, x);
        int yp = find(ss, y);
        if (xp != yp) ss[yp] = xp;
    }
    
    /*
     * We use disjoint set (or Union-Find) to detect a cycle in
     * an undirected graph.
     */
    vector<int> findRedundantConnection(vector<vector<int> >& e/*dges*/) {
        
        /* Create parent subsets and initialize them to -1 - this means
         * the subsets contain only one item - i.e ss[i] only contains
         * vertex i.
         */
        vector<int> ss; ss.push_back(-1);
        for (int i = 0; i < e.size(); i++) ss.push_back(i+1);
        
        /*
         * We go through each edge one by one. We find the subset
         * that the vertices of an edge belongs to. If they belong
         * to two different subsets, we merge them into one set 
         * using Union. Now, if both vertices are in the same 
         * subset, we got a cycle - we return it.
         *
         */
        for (int i = 0; i < e.size(); ++i) {
            int x = find(ss, e[i][0]), y = find(ss, e[i][1]);            
            if (x == y) return { e[i][0], e[i][1] };
            _union(ss, x, y);
        }
        
        /* No redundant edge found */
        return vector<int>();
    }
};