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
    bool Ans=0;
    bool isSame(TreeNode* a, TreeNode* b)
    {
        if(!a && !b) return 1;
        if(!a || !b) return 0;
        return (a->val==b->val && isSame(a->left,b->left) && isSame(a->right,b->right));
    }
    
    void Traverse(TreeNode* a,TreeNode* subRoot)
    {
        if(!a) return;

        if(a->val==subRoot->val && isSame(a,subRoot)) Ans= true;

        Traverse(a->left,subRoot);
        Traverse(a->right,subRoot);
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        Traverse(root,subRoot);
        return Ans;
    }
};