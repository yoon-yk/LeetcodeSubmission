class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        
        int mf = 0;
        unordered_map<int, int> mp;
        queue<TreeNode*> Q;
        if (root != NULL) {
            Q.push(root);
        }
        
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int val = cur->val;
            
            ++mp[val];
            if (mp[val] > mf){
                mf = mp[val];
            }
            
            if (cur->left) Q.push(cur->left);
            if (cur->right) Q.push(cur->right);
        }
        
        vector<int> ret;
        for (auto & [val, f] : mp) {
            if (f == mf) ret.push_back(val);
        }
        
        return ret;
    }
};