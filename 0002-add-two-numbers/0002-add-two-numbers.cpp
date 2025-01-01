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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        bool carry = false;
        struct ListNode *res = new ListNode(0);
        struct ListNode *rest = res;
        struct ListNode *tmp1 = l1;
        struct ListNode *tmp2 = l2;

        while(tmp1 && tmp2){
            int val1 = tmp1->val;
            int val2 = tmp2->val;

            int val = val1 + val2;

            if (carry) val++;
            carry = (val > 9);
            rest-> next = new ListNode(val % 10);
            rest = rest->next;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }

       while(tmp1){
        int val = tmp1->val;
        if(carry) val++;
        carry = (val > 9);
        rest->next = new ListNode(val % 10);
        rest = rest->next;
        tmp1 = tmp1->next;
       }

       while(tmp2){
        int val = tmp2->val;
        if(carry) val++;
        carry = (val > 9);
        rest->next = new ListNode(val % 10);
        rest = rest->next;
        tmp2 = tmp2->next;
       }

        if (carry){
            rest->next = new ListNode(1);
            rest = rest->next;
        }

        return res->next;
    }
};