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
        vector<pair<ListNode* , ListNode*>> nodes;
        ListNode* temp = head;
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
            nodes.push_back({first , second});
            if(i == k) reverse(first);
            else{
                nodes.pop_back();
                nodes.push_back({first,first});
            }
        }
        ListNode* dummyHead  = new ListNode(-1);
        ListNode* temp1 = dummyHead;
        for(auto& i : nodes){
            temp1->next = i.second;
            temp1 = i.first;
        }
        return dummyHead->next;
    }
};
