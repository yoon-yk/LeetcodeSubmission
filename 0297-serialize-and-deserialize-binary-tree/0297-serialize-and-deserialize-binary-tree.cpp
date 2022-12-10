/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // * Preorder로 해야 한다는 것 * //
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#";
        
        string s = to_string(root->val) + ',';
        s += serialize(root->left) + ',';
        s += serialize(root->right);
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream str(data);
        return inorderTraversal(str);
    }
    
    TreeNode* inorderTraversal(stringstream &s) {
        string str;
        getline(s, str, ',');
        if (str == "#") return NULL;
        
        TreeNode* root = new TreeNode(stoi(str));
        root->left = inorderTraversal(s);
        root->right = inorderTraversal(s);
        return root;
    }
    
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));