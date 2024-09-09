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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> matrix(m, vector<int>(n, -1));

        int startRow = 0, endRow = m-1, startCol = 0, endCol = n-1;
        while(head != NULL)
        {
            //  left to right
            for(int i = startCol; i <= endCol && head; i++) {
                matrix[startRow][i] = head->val;
                head = head->next;
            }
            startRow++;

            //  top to bottom
            for(int i = startRow; i <= endRow && head; i++) {
                matrix[i][endCol] = head->val;
                head = head->next;
            }
            endCol--;

            //  right to left
            for(int i = endCol; i >= startCol && head; i--) {
                matrix[endRow][i] = head->val;
                head = head->next;
            }
            endRow--;
            
            //  bottom to top
            for(int i = endRow; i >= startRow && head; i--) {
                matrix[i][startCol] = head->val;
                head = head->next;
            }
            startCol++;

        }
        return matrix;
    }
};