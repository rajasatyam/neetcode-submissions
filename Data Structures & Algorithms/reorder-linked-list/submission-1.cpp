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
    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        while(head){
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;

        ListNode* mid = findMid(head);
        ListNode* temp = reverse(mid->next);
        mid->next = nullptr;
        ListNode* temp1 = head;
        ListNode* curr = temp1;
        temp1 = temp1->next;

        while(temp){
            curr->next = temp;
            temp = temp->next;
            curr = curr->next;
            curr->next = temp1;
            temp1 = temp1->next;
            curr = curr->next;
        }
    }
};
