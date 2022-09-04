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
        
        unordered_map<int, vector<int>> m; // <# of vertical order, vector of node values>
        queue<pair<int, TreeNode*>> Q; // Make a pair of <vertical order, TreeNode pointer>  
       
        auto compare = [] (pair<int, TreeNode*> A, pair<int, TreeNode*> B) {
            return (A.second->val > B.second->val); 
        };
        
        priority_queue<pair<int, TreeNode*>, vector<pair<int, TreeNode*>>, decltype(compare)> pq(compare); // Declare min heap to sort the nodes by values in every level  
        
        int left = 0, right = 0; // Keep the most lowest vertical level and highest vertical level so we can access the level in order later when inserting to answer vector.
        int size;
        
        Q.push({0, root});

        while (!Q.empty()) {
            size = Q.size();
            
            while (size--) { // To access by (horizontal) level 
                auto cur = Q.front(); Q.pop();
                m[cur.first].push_back(cur.second->val);
                left = min(left, cur.first);
                right = max(right, cur.first);
                
                if (cur.second->left) 
                    pq.push({cur.first-1, cur.second->left});

                if (cur.second->right) 
                    pq.push({cur.first+1, cur.second->right});
            }
            
            while (!pq.empty()) { // Push into the queues in order of node value
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