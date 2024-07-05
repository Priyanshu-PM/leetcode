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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> indices;
        ListNode* prev = NULL;
        ListNode* dummy = head;
        int index = 0;
        while(dummy && dummy->next) {
            if(prev != NULL && dummy->val > prev->val && dummy->val > dummy->next->val) {
                indices.push_back(index);
            }
            else if(prev != NULL && dummy->val < prev->val && dummy->val < dummy->next->val) {
                indices.push_back(index);
            }
            prev = dummy;
            dummy = dummy->next;
            index++;
        }
        int n = indices.size();
        if(n < 2)   return {-1, -1};
        int mini = INT_MAX;
        for(int i = 0; i < n-1; i++) {
            mini = min(mini, indices[i+1] - indices[i]);
        }
        return {mini, indices[n-1] - indices[0]};
    }
};