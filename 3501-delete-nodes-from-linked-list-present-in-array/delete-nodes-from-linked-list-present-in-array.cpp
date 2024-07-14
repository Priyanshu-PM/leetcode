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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        set<int> st;
        for(int ele: nums)  st.insert(ele);

        ListNode* newHead = new ListNode(-1);
        ListNode* curr = head;
        ListNode* prev = newHead;

        while(curr != NULL)
        {
            if(st.find(curr->val) == st.end()) {
                prev->next = curr;
                prev = prev->next;
            }
            curr = curr->next;
        }
        prev->next = NULL;
        return newHead->next;
    }
};