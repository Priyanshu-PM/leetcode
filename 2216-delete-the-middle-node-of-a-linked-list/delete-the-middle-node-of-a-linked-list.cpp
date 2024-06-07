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
    int count = 0;
    void countTotal(ListNode* head) {
        while(head != NULL) {
            count++;
            head = head->next;
        }
    }

    ListNode* deleteMiddle(ListNode* head) {

        
        ListNode* temp = head;
        ListNode* dummy = head;
        
        countTotal(dummy);
        
        ListNode *prev, *next1;
        int c = 0;
        if(count == 1)  return NULL;

        while(temp != NULL && temp->next != NULL) {
            
            next1 = temp->next;
            prev = temp;
            temp = temp->next;
            c++;
            if(c == count/2) {
                prev->next = next1->next;

            }
        }
        return head;
    }
};