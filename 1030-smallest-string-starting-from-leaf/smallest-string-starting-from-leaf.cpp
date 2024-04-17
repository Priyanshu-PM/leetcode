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
void solve(TreeNode* root, string &ans, string temp)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
    {
        temp = (char)(root->val + 'a') + temp;
        if(ans == "" || ans > temp)
            ans = temp;
        return;
    }

    temp = (char)(root->val + 'a') + temp;
    if(root->left)  solve(root->left, ans, temp);
    if(root->right) solve(root->right, ans, temp);
    return;
}
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        solve(root, ans, "");
        return ans;
    }
};