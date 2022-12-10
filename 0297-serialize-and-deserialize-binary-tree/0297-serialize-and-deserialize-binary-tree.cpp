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
        stringstream s(data);
        return preorderTraversal(s);
    }
    
    TreeNode* preorderTraversal(stringstream& s) {
        string str;
        getline(s, str, ',');
        if (str == "#") return NULL;
        
        TreeNode* root = new TreeNode(stoi(str));
        root->left = preorderTraversal(s);
        root->right = preorderTraversal(s);
        
        return root;
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));