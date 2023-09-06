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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* p = head;
        int cnt = 0;
        while (p) {
            ++cnt;
            p = p->next;
        }

        vector<ListNode*> ret(k);
        int d = cnt / k;
        ListNode* h = head;
        if (d == 0) {
            for (int i=0; i<cnt; ++i) {
                ret[i] = h;
                h = h->next;
                ret[i]->next = NULL;
            }
        } else {
            int re = cnt % k;
            for (int i=0; i<k; ++i) {
                ret[i] = h;
                for (int j=0; h && j<d-1+ (re > 0); ++j) {
                    h = h->next;
                }
                --re;
                ListNode *tmp = h;
                if (h) {
                    tmp = h->next;
                    h->next = NULL;   
                    h = tmp;
                }
            }

        }
        
        return ret;
    }
};