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
    bool isPalindrome(ListNode* head) {
        string ans = "";
        while(head != NULL) {
            ans += to_string(head->val);
            head = head->next;
        }

        int n = ans.size();

        for(int i = 0; i < n; i++) {
            if(ans[i] != ans[--n]) return false;
        }

        return true;
    }
};