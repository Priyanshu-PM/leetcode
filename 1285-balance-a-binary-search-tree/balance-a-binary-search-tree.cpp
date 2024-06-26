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
    vector<TreeNode*> vec;
    void inOrder(TreeNode* root)
    {
        if(!root)   return;
        inOrder(root->left);
        vec.push_back(root);
        inOrder(root->right);
    }

    TreeNode* solve(int l, int r, vector<TreeNode*> vec)
    {
        if(l > r)   return NULL;
        int mid = l + (r - l)/2;

        TreeNode* root = vec[mid];
        root->left = solve(l, mid-1, vec);
        root->right = solve(mid+1, r, vec);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {

        TreeNode* temp = root;
        inOrder(temp);

        int l = 0;
        int r = vec.size()-1;

        return solve(l, r, vec);
    }
};