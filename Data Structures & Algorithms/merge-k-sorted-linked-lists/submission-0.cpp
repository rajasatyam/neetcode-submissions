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
    struct cmp{
        bool operator()(const ListNode* a , const ListNode* b){
            return a->val > b->val;
        };
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , cmp> pq;
        for(auto& i : lists){ 
            if(i) pq.push(i);
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* temp = dummyHead;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            if(temp->val == -1){
                temp->next = t;
                t = t->next;
                temp = temp->next;
            }
            while(t && t->val <= pq.top()->val){
                temp->next = t;
                t = t->next;
                temp = temp->next;
            }
            if(t) pq.push(t);
        }

        return dummyHead->next;
    }
};
