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
class cmp {

    public: 
        // operator overloading
        bool operator() (ListNode*a, ListNode* b) {
            return a->val > b->val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // using the min heap
        // we are storing the minimum element on the top

        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != NULL) q.push(lists[i]);
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* tail = dummyHead;

        while(!q.empty()) {

            // taking the minimum element from the top and adding it to the list

            ListNode* temp = q.top();
            tail->next = temp;
            tail = temp;
            q.pop();
            if(temp->next != NULL) {
                q.push(temp->next);
            }
        }
        return dummyHead->next;
    }
};