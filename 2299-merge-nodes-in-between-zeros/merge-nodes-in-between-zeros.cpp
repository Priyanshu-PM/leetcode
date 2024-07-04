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
    ListNode* mergeNodes(ListNode* head) {
        
        int sum = 0;
        ListNode* temp = head;
        ListNode* newNode = new ListNode(-1);
        ListNode* tail = newNode;
        while(temp != NULL)
        {
            if(temp->val == 0) {
                if(sum != 0)
                {
                    tail->next = new ListNode(sum);
                    tail = tail->next;
                    sum = 0;
                }
            }
            else {
                sum += temp->val;
            }
            temp = temp->next;
        }
        if(sum != 0) {
            tail->next = new ListNode(sum);
        }

        return newNode->next;
    }
};