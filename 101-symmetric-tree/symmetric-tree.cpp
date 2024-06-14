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
    bool areIdenticalTrees(TreeNode* lTree, TreeNode* rTree)
    {
        if(lTree == NULL || rTree == NULL)
            return (lTree == rTree);

        return (lTree->val == rTree->val) 
        &&  areIdenticalTrees(lTree->left, rTree->right)
        &&  areIdenticalTrees(lTree->right, rTree->left);

        //  comparing left node with right node and vice-versa
    }

public:
    bool isSymmetric(TreeNode* root) {

        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return true;

        return areIdenticalTrees(root->left, root->right);
    }
};