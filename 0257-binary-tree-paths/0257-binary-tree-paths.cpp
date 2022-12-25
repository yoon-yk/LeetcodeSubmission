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
    vector<string> binaryTreePaths(TreeNode* root) {
        queue<pair<TreeNode*, string>> tnQ;
        
        if (root) tnQ.push({root, to_string(root->val)});
        TreeNode* curTN;
        vector<string> ans;
        while (!tnQ.empty()) {
            auto cur = tnQ.front(); tnQ.pop();
            curTN = cur.first;
            string& curPath = cur.second;
            
            if (!curTN->left && !curTN->right) {
                ans.push_back(curPath);
            } else {
                if (curTN->left)
                    tnQ.push({curTN->left, curPath + "->" + to_string(curTN->left->val)});
                if (curTN->right)
                    tnQ.push({curTN->right, curPath + "->" + to_string(curTN->right->val)});
            }
        }
        return ans;
    }
};