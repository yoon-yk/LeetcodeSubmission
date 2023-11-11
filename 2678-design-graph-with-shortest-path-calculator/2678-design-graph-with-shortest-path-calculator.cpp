class Graph {
public:
    using ll = long long;
    vector<vector<ll>> mat;
    int n;
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        mat.resize(n, vector<ll>(n, INT_MAX));
        for (auto & e : edges) {
            mat[e[0]][e[1]] = e[2];
        }

        for (int i=0; i<n; ++i) mat[i][i] = 0;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                for (int k=0; k<n; ++k) {
                    mat[j][k] = min(mat[j][k], 
                                    mat[j][i] + mat[i][k]);
                }
            }
        }
    }
        void addEdge(vector<int> edge) {
        int n = mat.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mat[i][j] = min(mat[i][j], 
                mat[i][edge[0]] + mat[edge[1]][j] + edge[2]);
    }
    
    
    int shortestPath(int node1, int node2) {
        if (mat[node1][node2] == INT_MAX) return -1;
        return mat[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */