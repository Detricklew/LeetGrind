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
    struct ListNode * merge2lists(struct ListNode * a, struct ListNode * b){
        struct ListNode res = {0};
        
        struct ListNode *tmp = &res;

        while(a && b){
            if(a->val < b->val){
                tmp->next = a;
                a = a->next;
            }else{
                tmp->next = b;
                b = b->next;
            }

            tmp = tmp->next;
        }

        if(a){
            tmp->next = a;
        }

        if(b){
            tmp->next = b;
        }

        return res.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()){
            return NULL;
        }

        struct ListNode *res = lists[0];

        for (int i = 1; i < lists.size(); i++){
           res = merge2lists(res, lists[i]);
        }

        return res;
    }
};