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
public:
    int ans;
    int countCoins(TreeNode* root)
    {
        if(!root)   return 0;
        int leftCoins = countCoins(root->left);
        int rightCoins = countCoins(root->right);
        ans += abs(leftCoins) + abs(rightCoins);
        return (root->val - 1) + leftCoins + rightCoins;
    }

    int distributeCoins(TreeNode* root) {
        ans = 0;
        countCoins(root);
        return ans;
    }
};