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
    ListNode* deleteDuplicates(ListNode* head) {

        if(!head || !head->next)    return head;
        ListNode* nextt = head->next;
        
        if(nextt->val == head->val) {
            while(nextt && nextt->val == head->val) nextt = nextt->next;
            return deleteDuplicates(nextt);
        }
        else {
            head->next = deleteDuplicates(nextt);
            return head;
        }
    }
};