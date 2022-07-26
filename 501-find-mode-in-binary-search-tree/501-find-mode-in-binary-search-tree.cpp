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
    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        if (!root) return ans;
        
        stack<TreeNode*> st;
        unordered_map<int, vector<int>> hashM;
        TreeNode* curr = root;
        int prevV = 0, currV = curr->val, currFreq = -1, maxFreq = -1;
        
        while (!st.empty() || curr){
            
            // left
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // middle
            curr = st.top(); st.pop();
            prevV = currV;
            currV = curr->val;
            if (currFreq < 0) {
                currFreq = 1;
            }
            else {
                if (currV != prevV) {
                    hashM[currFreq].push_back(prevV);
                    maxFreq = max(maxFreq, currFreq);
                    currFreq = 1;  
                }
                else {
                    currFreq++;
                } // the last node?

            }
            
            // right
            curr = curr->right;
            
        }
        
        if (currFreq > 0) {
            hashM[currFreq].push_back(currV);
            maxFreq = max(maxFreq, currFreq);
        }
        
        
        // inorder -> sorted array ==> queue 
        // 1 2 2 3 3 3 3 
        
        
        // if (curr!= prev) => compare with current mode
        //  if current accum is bigger, update the current mode ==> add hashMap[currentOccurence].push_back(curr->val)
        // else current accum ++;
        
        // iterate over the hashMap 
        
        return hashM[maxFreq];
    }
};