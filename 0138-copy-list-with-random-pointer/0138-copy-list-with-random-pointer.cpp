/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> visited;
        unordered_map<Node*,vector<Node*>> random;

        Node* NewHead = new Node(0);
        Node* tmp = NewHead;

        while(head){
            tmp->next = new Node(head->val);
            tmp = tmp->next;
            visited[head] = tmp;

            if(visited.find(head->random) == visited.end()){
                random[head->random].push_back(tmp);
            }else{
                tmp->random = visited[head->random];
            }

            if(random.find(head) != random.end()){
                for(Node* k: random[head]){
                    k->random = tmp;
                }
            }

            head = head->next;
        }

        return NewHead->next;
    }
};