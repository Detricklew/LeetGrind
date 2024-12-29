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
    void reorderList(ListNode* head) {
        struct ListNode *s = head;
        struct ListNode *f = head;

        while(f->next && f->next->next){
            s = s->next;
            f = f->next->next;
        }

        f = NULL;

        while (s){
            struct ListNode *tmp = s->next;
            s->next = f;
            f = s;
            s = tmp;
        }

        while(head && f){
            struct ListNode *tmp1 = head->next;
            struct ListNode *tmp2 = f->next;

            head->next = f;
            f->next = tmp1;
            head = tmp1;
            f = tmp2;
        }
    }
};