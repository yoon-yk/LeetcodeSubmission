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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curTrack;
        
        pathSum(root, targetSum, curTrack, ans);
        return ans;
    }
    
    void pathSum(TreeNode* root, int targetSum, vector<int>& curTrack, vector<vector<int>>& ans){
        if (root==NULL) return;
        
       curTrack.push_back(root->val);

        if (!root->left && !root->right && root->val == targetSum)
            ans.push_back(curTrack);
        
        pathSum(root->left, targetSum-root->val, curTrack, ans);
        pathSum(root->right, targetSum-root->val, curTrack, ans);
        
        curTrack.pop_back(); // 나 말고 children 이 내 관련 노드 모두 뺀 curTrack 가질 수 있게 
        
    }
};