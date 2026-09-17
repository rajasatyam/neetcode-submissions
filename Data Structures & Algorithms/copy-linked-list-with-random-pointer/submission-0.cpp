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
        Node* newHead = new Node(-1);
        Node* temp1 = newHead;
        Node* temp = head;
        unordered_map<Node* , Node*> mpp;
        while(temp){
            Node* nxt = new Node(temp->val);
            mpp[temp] = nxt;
            temp1->next = nxt;
            temp1 = temp1->next;
            temp = temp->next;
        }
        temp = head;
        temp1 = newHead->next;
        while(temp){
            if(temp->random){
                temp1->random = mpp[temp->random];
            }
            temp1 = temp1->next;
            temp = temp->next;
        }

        return newHead->next;
    }
};
