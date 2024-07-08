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
    ListNode* reverseList(ListNode* head) {
        // ListNode* newHead = NULL;
        // while(head != NULL) {
        //     ListNode* next = head->next;
        //     head->next =  newHead;
        //     newHead = head;
        //     head = next;
        // }

        // return newHead;
            // Base case:
        // If the linked list is empty or has only one node,
        // return the head as it is already reversed.
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // Recursive step:
        // Reverse the linked list starting 
        // from the second node (head->next).
        ListNode* newHead = reverseList(head->next);
        
        // Save a reference to the node following
        // the current 'head' node.
        ListNode* front = head->next;
        
        // Make the 'front' node point to the current
        // 'head' node in the reversed order.
        front->next = head;
        
        // Break the link from the current 'head' node
        // to the 'front' node to avoid cycles.
        head->next = NULL;
        
        // Return the 'newHead,' which is the new
        // head of the reversed linked list.
        return newHead;
    }
};