/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

void inOrder(TreeNode* root, vector<int>& ans, int k) {
    
    if(!root || ans.size() > k) return;

    inOrder(root->left, ans, k);
    if(ans.size() < k)
        ans.push_back(root->val);

    inOrder(root->right, ans, k);
}
public:
    int kthSmallest(TreeNode* root, int k) {

        vector<int> ans;
        inOrder(root, ans, k);

        return ans.back();
    }
};