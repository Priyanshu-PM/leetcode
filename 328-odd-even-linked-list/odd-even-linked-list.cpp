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
    ListNode* oddEvenList(ListNode* head) {
       
       if(head == NULL) return NULL;

       if(head->next == NULL || head->next->next == NULL) {
           return head;
       }

       ListNode* odd = head;
       ListNode* even = head->next;
       ListNode* temp = head->next->next;
       ListNode* resEven = head->next;

       int i = 2;
       while(temp != NULL) {

           if(i%2 == 0) {
               odd->next = temp;
               odd = odd->next;
           }
           else {
               even->next = temp;
               even = even->next;
           }
           temp = temp->next;
           i++;
       }

       odd->next = resEven;
       even->next = NULL;

       return head;

    }
};