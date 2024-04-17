/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* tempa = headA;
        ListNode* tempb = headB;

        while(tempa || tempb)
        {
            if(tempa == NULL)
                tempa = headA;
            if(tempb == NULL)
                tempb = headB;
            
            if(tempa == tempb)    return tempa;
            tempa = tempa->next;
            tempb = tempb->next;
        }
        return NULL;
    }
};