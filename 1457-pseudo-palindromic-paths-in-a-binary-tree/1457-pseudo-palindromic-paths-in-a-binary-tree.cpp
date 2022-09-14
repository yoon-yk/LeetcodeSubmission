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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> cnt(10, 0);
        
        if (!root) return 0;
        
        cnt[root->val]++;
        
        return dfs(root, cnt);
    }
    
    int dfs(TreeNode* root, vector<int>& cnt) {
        
        if (!root) return 0;
        
        int pCnt = 0, nOdd = 0, nEven = 0;
        

        if (!root->left && !root->right) { // reached the leaf node
            for (int i=1; i<=9; i++) {
                if (cnt[i]%2) nOdd++;
                else nEven++;
            }
            
            cout << nOdd << " " << nEven << endl;
            // 모두 짝수 || 하나만 홀수 
            // -> 홀수가 두개 이상이면 탈락
            if (nOdd > 1) return 0;
            else return 1;
        }
        
        if (root->left) {
            cnt[root->left->val] ++;
            pCnt += dfs(root->left, cnt);
            cnt[root->left->val] --;
        }
        
        if (root->right) {
            cnt[root->right->val] ++;
            pCnt += dfs(root->right, cnt);
            cnt[root->right->val] --;
        }
        
        return pCnt;
        
    }
};