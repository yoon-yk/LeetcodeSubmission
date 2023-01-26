/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int initializeAdjList(TreeNode* root, vector<vector<int>>& adjList) {
        
        int val;
        if (root->left) {
            val = initializeAdjList(root->left, adjList);
            adjList[root->val].push_back(val);
            adjList[val].push_back(root->val);
        }
        
        if (root->right) {
            val = initializeAdjList(root->right, adjList);
            adjList[root->val].push_back(val);
            adjList[val].push_back(root->val);
        }
        
        return root->val;
    }
    
    void topo_traverse(int target, int k, vector<vector<int>>& adjList, vector<int>& ans) {
        queue<pair<int, int>> Q;
        int size, level = 0;
        
        Q.push({target, -1}); // cur, parent
        while (!Q.empty() && level < k) {
            size = Q.size();
            while (size--) {
                auto [cur, par] = Q.front(); Q.pop();
                
                for (auto & nei : adjList[cur]) {
                    if (nei == par) continue;
                    Q.push({nei, cur});
                }
            }
            ++level;
        }
        
        while (!Q.empty()) {
            ans.push_back(Q.front().first); Q.pop();
        }
        
    }

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int>> adjList(500);
        if (root) initializeAdjList(root, adjList);
        
        vector<int> ans;
        topo_traverse(target->val, k, adjList, ans);
        return ans;
    }
};