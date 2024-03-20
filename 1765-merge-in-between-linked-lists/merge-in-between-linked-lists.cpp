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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        ListNode* dummy = list1;
        for(int i = 1; i < a; i++)  dummy = dummy->next;

        ListNode* end = dummy;
        for(int i = a-1; i <= b; i++)    end = end->next;

        while(list2)
        {
            dummy->next = list2;
            dummy = dummy->next;
            list2 = list2->next;
        }

        dummy->next = end;
        return list1;
        
    }
};