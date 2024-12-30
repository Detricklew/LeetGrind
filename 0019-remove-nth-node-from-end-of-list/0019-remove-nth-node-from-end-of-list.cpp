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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        struct ListNode *e = head;

        struct ListNode *s = head;
        int count = 0;

        while(s){
            if (count > n){
                e = e->next;
            }
             count++;
            s = s->next;  
        }

        if (count == n){
            cout<<"same"<<endl;
            cout<<e->val<<endl;
            e = e->next;
            if(e){
                cout<<e->val<<endl;
            }else{
                cout<<"NULL"<<endl;
            }
            return e;
        }

        if (count > n){
            cout<<"greater"<<endl;
            cout<<e->val<<endl;
            e->next = e->next->next;
            if(e){
                cout<<e->val<<endl;
            }else{
                cout<<"NULL"<<endl;
            }
            
            return head;
        }

        return head;
    }
};