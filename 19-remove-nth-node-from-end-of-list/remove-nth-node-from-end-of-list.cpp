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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = head;
        ListNode* dummy = head;

        // counting the number of nodes in the list
        countTotal(dummy);
        int z = count - n + 1;
        ListNode* prev;
        ListNode* next1;
        int c = 0;

        // checking if only one present in the list
        if(z == 1) {
            return head->next;
        }
        while(temp != NULL && temp->next != NULL) {

            
            next1 = temp->next;
            prev = temp;
            temp = temp->next;
            c++;
            if(c + 1 == z) {
                prev->next = next1->next;

            }
        }

        return head;
    }

};