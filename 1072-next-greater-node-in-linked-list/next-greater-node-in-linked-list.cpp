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
    void solve(ListNode* head, vector<int>& ans, stack<int>& st)
    {
        //  similar to next greater element approach
        if(head == NULL)    return;

        //  recursively iterate till the end of the linked list
        solve(head->next, ans, st);
        while(!st.empty() && st.top() <= head->val)
            st.pop();

        if(!st.empty())    ans.push_back(st.top());
        else    ans.push_back(0);

        st.push(head->val);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* temp = head;
        vector<int> ans;
        stack<int> st;
        solve(temp, ans, st);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};