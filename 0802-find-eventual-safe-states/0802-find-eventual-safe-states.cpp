class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> isSafe(graph.size(), -1);
        for (int i=0; i<graph.size(); ++i) {
            auto & elist = graph[i];
            if (elist.empty()) {
                isSafe[i] = true;
            }
        }
        
        vector<int> ans;
        for (int i=0; i<graph.size(); ++i) {
            if (testSafety(i, isSafe, graph)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    
    bool testSafety(int i, vector<int>& isSafe, vector<vector<int>>& graph) {
        if (isSafe[i] != -1) return isSafe[i];
        
        isSafe[i] = false;
        bool ans = true;
        for (auto & e : graph[i]) {
            if (!testSafety(e, isSafe, graph)) ans = false;
        }
        return isSafe[i] = ans;
    }
};