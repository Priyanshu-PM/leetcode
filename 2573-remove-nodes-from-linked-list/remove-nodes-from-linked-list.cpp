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
    void solve(ListNode* head, int& biggest, vector<ListNode*>& ans)
    {
        if(head == NULL)    return;
        solve(head->next, biggest, ans); 
        
        if(biggest <= head->val)
        {
            ans.push_back(head);
            biggest = head->val;
        }
    }
    ListNode* removeNodes(ListNode* head) {

        ListNode* temp = head;
        vector<ListNode*> v;
        while(temp) {
            v.push_back(temp);
            temp = temp->next;
        }

        int biggest = 0;
        ListNode* nextEle = NULL;
        for(int i = v.size()-1; i >= 0; i--) {
            
            if(v[i]->val >= biggest) {
                biggest = max(v[i]->val, biggest);
                v[i]->next = nextEle;
                nextEle = v[i];
            }
        }
        return nextEle;
    }
};