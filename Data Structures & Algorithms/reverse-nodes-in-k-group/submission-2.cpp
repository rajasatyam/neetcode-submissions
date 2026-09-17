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
    void reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* dummyHead  = new ListNode(-1);
        ListNode* temp1 = dummyHead;
        while(temp){
            ListNode* first = temp;
            int i = 1;
            while(temp->next && i < k){
                temp = temp->next;
                i++;
            }
            ListNode* second = temp;
            temp = temp->next;
            second->next = nullptr;
            if(i == k){
                reverse(first);
                temp1->next = second;
                temp1 = first;
            }
            else{
                temp1->next = first;
                temp1 = first;
            }
        }
        return dummyHead->next;
    }
};
