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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        vector<int> value;
        ListNode* temp = head;
        while(temp){
            value.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        int j = value.size() - 1;
        while(temp){
            temp->val = value[j--];
            temp = temp->next;
        }
        return head;
    }
};
