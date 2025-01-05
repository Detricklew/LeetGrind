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
    ListNode* reverseKGroup(ListNode* head, int k) {
        struct ListNode res = ListNode(0);
        res.next = head;
        int count = 0;
        struct ListNode *l = head;
        struct ListNode *h = head;
        struct ListNode *l2 = NULL;

        while(h){
            h = h->next;
            count++;
            if(count == k){
                struct ListNode * prev = h;
                struct ListNode * cur = l;
                struct ListNode * lc = l2;

                l2 = l;

                while(cur != h){
                    struct ListNode* tmp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = tmp;
                }
                
                if(lc){
                    lc->next = prev;
                }

                if(l==head){
                    res.next = prev;
                }
                count = 0;
                l=h;
            }
        }

        return res.next;
    }
};