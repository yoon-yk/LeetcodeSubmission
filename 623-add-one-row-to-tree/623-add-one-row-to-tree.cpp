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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // depth-1 에 있는 p노드가 d 방향에 c노드를 갖고 있다면,
        // n노드를 생성하여 n노드의 d방향의 child가 c노드를 가리키도록 하고
        // p 노드의 d방향의 child는 n노드를 가리키도록 한다. 
        
        // 레벨별로 접근 하는 법 -> BFS 
        // depth 가 1이라면? --> dummyRoot 노드 만들어주고 레벨 카운트는 0부터 시작하기
        
        // depth가 dep of tree + 1이라면? 
        // 모든 leaf 노드에 달아주기 
        
        TreeNode* dummyHead = new TreeNode();
        dummyHead->left = root;
        
        int curDep = 0;
        queue<TreeNode*> q;
        q.push(dummyHead);
        
        int size;
        while (!q.empty()) {
            size = q.size();
            
            while (size--) {
                auto cur = q.front(); q.pop();
                if (depth-1 == curDep) {
                    TreeNode* newTNl = new TreeNode();
                    newTNl->val = val;
                    newTNl->left = cur->left;
                    cur->left = newTNl;
                    
                    TreeNode* newTNr = new TreeNode();
                    newTNr->val = val;
                    newTNr->right = cur->right;
                    cur->right = newTNr;
                }
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            curDep ++;
        }
        
        
        return dummyHead->left;
    }
};