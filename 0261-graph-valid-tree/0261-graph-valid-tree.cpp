class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if (edges.size() != (n-1)) return false;
        
        stack<int> st;
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        
        for (auto& e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        int cnt = n;
        st.push(0);
        visited[0] = true;
        
        while (!st.empty()) {

            auto cur = st.top(); st.pop();
            cnt --;

            for (int& nei : adjList[cur]) {
                if (visited[nei]) continue;
                visited[nei] = true;
                st.push(nei);
            }
        }
        
        return (cnt == 0);
    }    
            
};