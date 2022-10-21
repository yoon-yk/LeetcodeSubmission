class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        stack<pair<int, int>> st;
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        
        for (auto& e : edges){
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        int cnt = n;
        st.push({0, -1});
        visited[0] = true;
        
        while (!st.empty()) {

            auto cur = st.top(); st.pop();
            cnt --;
            int curNode = cur.first;
            int parNode = cur.second;

            for (int& nei : adjList[curNode]) {
                if (parNode == nei) continue;
                if (visited[nei]) return false;
                visited[nei] = true;
                st.push({nei, curNode});
            }
        }
        
        return (cnt == 0);
    }    
            
};