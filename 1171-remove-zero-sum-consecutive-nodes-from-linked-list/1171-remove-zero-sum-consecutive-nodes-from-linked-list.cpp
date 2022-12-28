/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*
    d  1  2 -3  3  1
    0  1  3  0  3  1 
    
    
       1  2  3  -3  4
    0  1  3  6   3  4
    
    
       1  2  4
    0  1  3  4
    
    d  1  2  3 -3 -2
    0  1  3  6  3  1
    
    
    d -1  1  2  3 -2 -3 -1 -4 -2  2  4 
    0 -1  0  2  5  3  0 -1 -5 -7 -5 -1
    
    d -----  2  3 -2 -3 -1 -4 -2  2  4 
    0 -1  0  2  5  3  0 -1 -5 -7 -5 -1
    
    d ----------------- -1 -4 -2  2  4 
    0 -1  0  2  5  3  0 -1 -5 -7 -5 -1
    
    d ----------------- -1 -4 ------ 4 
    0 -1  0  2  5  3  0 -1 -5 -7 -5 -1

    */
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* ptr = dummyHead;
        int prefix = 0;
        
        while (ptr) {
            prefix += ptr->val;
            // cout << prefix << " " << ptr->val << endl;

            if (mp.count(prefix)) {
                ListNode* del =  mp[prefix]->next;
                int p = prefix + del->val;
                while (p != prefix) {
                    mp.erase(p);
                    del = del->next;
                    p += del->val;
                }
                mp[prefix]->next = ptr->next;
            }
            else mp[prefix] = ptr;
            ptr = ptr->next;
            
//             ListNode* pptr = dummyHead;
//             cout << "**LL**" << endl;
//             while (pptr) {
//                 cout << pptr->val << " ";
//                 pptr = pptr->next;
//             }
//             cout << endl;
//             cout << "**MAP**" << endl;
//             for (auto [i,_] : mp) cout << i << " ";
//             cout << endl;
        }
        

        
        return dummyHead->next;
    }
};