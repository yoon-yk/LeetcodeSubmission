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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> Q;
        
        auto compare = [] (pair<int, TreeNode*> A, pair<int, TreeNode*> B) {
            return (A.second->val > B.second->val);
        };
        
        priority_queue<pair<int, TreeNode*>, vector<pair<int, TreeNode*>>, decltype(compare)> pq(compare);
        Q.push({0, root});
        
        int left = 0, right = 0, size;
        while (!Q.empty()) {
            size = Q.size();
            
            while (size--) {
                auto cur = Q.front(); Q.pop();
                m[cur.first].push_back(cur.second->val);
                left = min(left, cur.first);
                right = max(right, cur.first);
                
                if (cur.second->left) 
                    pq.push({cur.first-1, cur.second->left});

                if (cur.second->right) 
                    pq.push({cur.first+1, cur.second->right});
            }
            
            while (!pq.empty()) {
                auto cur = pq.top(); pq.pop();
                Q.push(cur);
            }
        }
        
        vector<vector<int>> ans;
        for (int i=left; i<=right; i++) {
            ans.push_back(m[i]);
        }
            
        return ans;
    }
};