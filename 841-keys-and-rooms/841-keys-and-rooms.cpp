class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int size = rooms.size();
        int src = 0;
        int cnt = 0;
        
        vector<bool> visited(size, false);
        stack<int> st;
        st.push(src);
        visited[src] = true;
    
        int cur;
        while (!st.empty()) {
            cur = st.top(); st.pop();
            cnt ++;
            
            for (int i : rooms[cur]) {
                if (!visited[i]) {
                    visited[i] = true;
                    st.push(i);
                }
            }
        }
        
        return (cnt == size);
    }
};