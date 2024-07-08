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
    TreeNode* buildRecursiveTree(vector<int>& postOrder, int postStart, int postEnd, vector<int>& inOrder, int inStart, int inEnd, map<int, int>& inMap)
    {
        if(postStart > postEnd || inStart > inEnd)    return NULL;

        TreeNode* root = new TreeNode(postOrder[postEnd]);

        int inRoot = inMap[root->val];

        int numsLeft = inRoot - inStart;

        root->left = buildRecursiveTree(postOrder, postStart, postStart + numsLeft - 1, inOrder, inStart, inRoot - 1, inMap);
        root->right = buildRecursiveTree(postOrder, postStart + numsLeft, postEnd - 1, inOrder, inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int, int> inMap;
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        TreeNode* root = buildRecursiveTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};