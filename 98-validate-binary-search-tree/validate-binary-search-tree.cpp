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

void inOrder(TreeNode* root, vector<int>& ls)
{
    if(root == NULL)
        return;
    inOrder(root->left, ls);
    ls.push_back(root->val);
    inOrder(root->right, ls);
}

public:
    bool isValidBST(TreeNode* root) {
        
        vector<int> ls;

        //  traverse in inorder manner
        inOrder(root, ls);

        //  if inorder is in sorted manner, then it is BST
        for(int i = 0; i < ls.size()-1; i++)
            if(ls[i] >= ls[i+1])    return false;

        return true;
    }
};