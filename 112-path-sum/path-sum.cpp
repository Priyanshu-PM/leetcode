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

private:
    bool findSum(TreeNode* root, int targetSum, int sum)
    {
        if(root == NULL)
            return false;

        if(root->left == NULL && root->right == NULL)
        {
            sum = sum + root->val;
            if(sum == targetSum)
                return true;
        }
        
        bool left = findSum(root->left, targetSum, sum + root->val);
        bool right = findSum(root->right, targetSum, sum + root->val);

        return (left || right);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root == NULL)
            return false;
        
        return findSum(root, targetSum, 0);
    }
};