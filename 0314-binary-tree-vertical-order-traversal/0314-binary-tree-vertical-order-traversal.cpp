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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> mp;
        int rootLevel = 0;
        queue<pair<TreeNode*, int>> Q;
        if (root) Q.push({root, 0});
        
        while (!Q.empty()) {
            auto top = Q.front(); Q.pop();
            TreeNode* ptr = top.first;
            int curLv = top.second;
            mp[curLv].push_back(ptr->val);
            
            if (ptr->left)
                Q.push({ptr->left, curLv-1});
            if (ptr->right)
                Q.push({ptr->right, curLv+1});
        }
        
        vector<vector<int>> ans;
        for (auto & v : mp)
            ans.push_back(v.second);
        
        return ans;
    }
    
};