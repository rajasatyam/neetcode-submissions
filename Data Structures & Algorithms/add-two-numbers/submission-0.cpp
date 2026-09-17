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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* temp = NULL;
        ListNode* newHead = NULL;
        int carry = 0;
        while(temp1 || temp2){
            int curr = carry + (temp1 ? temp1->val : 0) + (temp2 ? temp2->val : 0);
            carry = curr / 10;
            ListNode* n = new ListNode(curr % 10);
            if(!temp){
                temp = n;
                newHead = temp;    
            }
            else{
                temp->next = n;
                temp = temp->next;
            }
            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }
        if(carry){
            temp->next = new ListNode(carry);
        }
        return newHead;
    }
};
