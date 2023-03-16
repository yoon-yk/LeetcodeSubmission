/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void init(TreeNode* root, vector<vector<int>> &adjList) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            auto cur = st.top(); st.pop();
            if (cur->left) {
                adjList[cur->val].push_back(cur->left->val);
                adjList[cur->left->val].push_back(cur->val);
                st.push(cur->left);
            }
            if (cur->right) {
                adjList[cur->val].push_back(cur->right->val);
                adjList[cur->right->val].push_back(cur->val);
                st.push(cur->right);
            }
        }
    }
    
    int dfs(int node, vector<bool>& visited, vector<vector<int>>& adjList) {
        
        int ans = 1;
        stack<int> st;
        st.push(node);
        
        while (!st.empty()) {
            auto cur = st.top(); st.pop();

            for (auto & nei : adjList[cur]) {
                if (visited[nei]) continue;
                ++ans;
                visited[nei] = true;
                st.push(nei);
            }
        }
        
        fill(visited.begin(), visited.end(), false);
        return ans;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        vector<vector<int>> adjList(n+1);
        init(root, adjList);
        
        int maxCount = 0, cnt;
        vector<bool> visited(n+1, false);
        for (auto & nei : adjList[x]) {
            visited[x] = visited[nei] = true;
            cnt = dfs(nei, visited, adjList);
            maxCount = max(maxCount, cnt);
        }
        
        return maxCount > (n >> 1);
    }
};