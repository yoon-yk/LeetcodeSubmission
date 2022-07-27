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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        if (descriptions.size() == 0) return nullptr;
        
        unordered_map<int, int> leftChild;
        unordered_map<int, int> rightChild;
        unordered_map<int, int> parent; 
        
        for (vector<int>& des : descriptions) {
            if(des[2])
                leftChild[des[0]] = des[1];
            else
                rightChild[des[0]] = des[1];
            parent[des[1]] = des[0];
        }
        
        int root = descriptions[0][0]; // any leaf node can do 
        while (parent.find(root)!=parent.end()){
            root = parent[root];
        }
        
        return constructTree(root, leftChild, rightChild);            
        
    }
    
    TreeNode* constructTree(int val, unordered_map<int, int>& leftChild, unordered_map<int, int>& rightChild) {
        
        TreeNode* root = new TreeNode(val);
        
        if (leftChild.find(val)!=leftChild.end())
            root->left = constructTree(leftChild[val], leftChild, rightChild);
        
        if (rightChild.find(val)!=rightChild.end())
            root->right = constructTree(rightChild[val], leftChild, rightChild);
        
        return root;
    }
};