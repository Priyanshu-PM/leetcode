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
    bool isLeaf(TreeNode* root) {
        return (root->left == NULL && root->right == NULL);
    }

    TreeNode* deleteNode(TreeNode* root, TreeNode* parent, int target) {
        if(root == NULL)    return NULL;

        root->left = deleteNode(root->left, root, target);
        root->right = deleteNode(root->right, root, target);

        if(isLeaf(root) && root->val == target) {
            if(parent)  delete root;
            return NULL;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return deleteNode(root, NULL, target);
    }
};