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
    
    ListNode* reverse(ListNode* head)
    {
        // Initialize current, previous and next pointers
        ListNode* current = head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    
    ListNode* doubleIt(ListNode* head) {

        ListNode* reversedList = reverse(head);
        int carry = 0;
        ListNode* current = reversedList, *prev = NULL;

        while(current != NULL) {
            
            int newValue = current->val * 2 + carry;
            current->val = newValue % 10;
            
            if(newValue > 9)    carry = 1;
            else    carry = 0;

            prev = current;
            current = current->next;
        }

        if(carry != 0) {
            ListNode* extra = new ListNode(carry);
            prev->next = extra;
        }

        ListNode* result = reverse(reversedList);
        return result;
    }
};