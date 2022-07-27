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
        
        unordered_map<int, TreeNode*> nodeMap;
        unordered_map<int, int> parentMap; 
        
        for (vector<int>& v : descriptions) {
            
            TreeNode* parent = (nodeMap.count(v[0]) > 0)? 
                nodeMap[v[0]] : (nodeMap[v[0]] = new TreeNode(v[0]));
            TreeNode* child = (nodeMap.count(v[1]) > 0)? 
                nodeMap[v[1]] : (nodeMap[v[1]] = new TreeNode(v[1]));
            
            if(v[2]) parent->left = child;
            else parent->right = child;
            
            parentMap[v[1]] = v[0];
        }
        
        int root = descriptions[0][0]; // any leaf node can do 
        while (parentMap.count(root) > 0){
            root = parentMap[root];
        }
        
        return nodeMap[root];   
    }
};