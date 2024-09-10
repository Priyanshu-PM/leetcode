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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* prev = new ListNode(-1);
        ListNode* dummy = head;
        while(dummy != NULL)
        {
            if(prev->val == -1)
            {
                prev = dummy;
                dummy = dummy->next;
                continue;
            }

            ListNode* newNode = new ListNode(__gcd(prev->val, dummy->val));
            newNode->next = prev->next;
            prev->next = newNode;

            prev = dummy;
            dummy = dummy->next;

        }
        return head;
    }
};