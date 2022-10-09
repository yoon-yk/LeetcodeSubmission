// This will give next greater element in average of O(1) time 
// and O(h) space
class BSTIterator {
private:
    stack<TreeNode*> stk;
    
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode * node = stk.top();
        stk.pop();
        
        pushAll(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    } 
    
    void pushAll(TreeNode* root) {
        TreeNode* curr = root;
        while(curr) {
            stk.push(curr);
            curr = curr->left;
        }
    }
};

// This will give next smaller element average of in O(1) time
// and O(h) space
class revBSTIterator {
private:
    stack<TreeNode*> stk;

public:
    revBSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        
        pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    
    void pushAll(TreeNode* root) {
        TreeNode * curr = root;
        while(curr) {
            stk.push(curr);
            curr = curr->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator left(root); // to get next greater element
        revBSTIterator right(root); // to get next smaller element
        
        int lo = left.next(), hi = right.next(); // lo is smallest element && hi is greatest element
        while (lo < hi) {
            
            if(lo + hi == k) return true;
            
            else if(lo + hi < k) {
                if(!left.hasNext()) break;
                lo = left.next();     
            }
            
            else {
                if(!right.hasNext()) break;
                hi = right.next();
            }
        }
        
        return false;
    }
};