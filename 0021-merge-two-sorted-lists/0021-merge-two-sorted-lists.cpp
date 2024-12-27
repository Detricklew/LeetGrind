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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode res(0);
        struct ListNode *tmp = &res; 

        struct ListNode *l1 = list1;
        struct ListNode *l2 = list2;

        while(l1 && l2){
            if(l1->val > l2->val){
                tmp->next = l2;
                l2 = l2->next;
                
            }
            else{
                tmp->next = l1;
                l1 = l1->next;
            }
            
            tmp = tmp->next;
        }

        if(l1){
            tmp->next = l1;
        }

        if(l2){
            tmp->next = l2;
        }

        return res.next;
    }
};