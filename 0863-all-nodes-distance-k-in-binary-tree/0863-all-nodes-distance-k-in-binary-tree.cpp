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
    int initializeAdjList(TreeNode* root, unordered_map<int, vector<int>>& adjList) {
        
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
    
    void topo_traverse(int target, int k, unordered_map<int, vector<int>>& adjList, vector<int>& ans) {
        unordered_set<int> visited;
        queue<int> Q;
        int size, level = 0;
        
        Q.push(target);
        while (!Q.empty() && level < k) {
            size = Q.size();
            while (size--) {
                auto cur = Q.front(); Q.pop();
                visited.insert(cur);
                
                for (auto & nei : adjList[cur]) {
                    if (visited.count(nei)) continue;
                    Q.push(nei);
                }
            }
            ++level;
        }
        
        while (!Q.empty()) {
            ans.push_back(Q.front()); Q.pop();
        }
        
    }

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> adjList;
        if (root) initializeAdjList(root, adjList);
        
        vector<int> ans;
        topo_traverse(target->val, k, adjList, ans);
        return ans;
    }
};