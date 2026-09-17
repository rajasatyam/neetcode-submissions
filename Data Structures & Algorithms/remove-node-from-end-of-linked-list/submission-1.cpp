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
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        ListNode* temp = head;
        ListNode* revHead = reverse(temp);
        ListNode* curr = revHead;
        ListNode* prev = nullptr;
        if(n == 1){
            ListNode* nxt = curr->next;
            curr->next = nullptr;
            curr = nxt;
            return reverse(curr);
        }
        int i = 1;
        while(curr){
            if(i == n){
                ListNode* nxt = curr->next;
                curr->next = nullptr;
                prev->next = nxt;
                break;
            }
            prev = curr;
            curr = curr->next;
            i++;
        }

        return reverse(revHead);
    }
};
