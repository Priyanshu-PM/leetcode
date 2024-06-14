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
    TreeNode* buildRecursiveTree(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd, map<int, int>& inMap)
    {
        if(preStart > preEnd || inStart > inEnd)
            return NULL;

        TreeNode* root = new TreeNode(preOrder[preStart]);
        
        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;

        root->left = buildRecursiveTree(preOrder, preStart + 1, preStart + numLeft, inOrder, inStart, inRoot - 1, inMap);
        root->right = buildRecursiveTree(preOrder, preStart + numLeft + 1, preEnd, inOrder, inRoot + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;

        //  creating the hashmap of all the nodes
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        TreeNode* root = buildRecursiveTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

        return root;

    }
};