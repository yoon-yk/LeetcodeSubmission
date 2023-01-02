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
        return encode(root);
    }
    
    string encode(TreeNode* root) {
        if (!root) return "#";
        string s = to_string(root->val) + ',';
        s += encode(root->left)+',';
        s += encode(root->right);
        
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream s(data);
        return decode(s);
    }
    
    TreeNode* decode(stringstream &s) {
        string str;
        getline(s, str, ',');
        if (str == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = decode(s);
        root->right = decode(s);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;