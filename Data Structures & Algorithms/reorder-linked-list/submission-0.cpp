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
        if(!head || !head->next) return;
        vector<ListNode*> nodes;
        ListNode* temp = head;
        while(temp){
            ListNode* curr = temp;
            temp = temp->next;
            curr->next = NULL;
            nodes.push_back(curr);
        }
        int i = 0 , j = nodes.size() - 1;
        temp = nodes[i++];
        while(i < j){
            temp->next = nodes[j--];
            temp = temp->next;
            temp->next = nodes[i++];
            temp = temp->next;
        }
        if(nodes.size() % 2 == 0) temp->next = nodes[i];

    }
};
