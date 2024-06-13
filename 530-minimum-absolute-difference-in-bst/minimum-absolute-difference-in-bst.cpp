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
    void inOrder(TreeNode* root, vector<int> & v)
    {
        if(root == NULL)    return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inOrder(root, v);

        int diff = INT_MAX;
        for(int i = 1; i < v.size(); i++)
            diff = min(diff, v[i] - v[i-1]);
        if(diff == INT_MAX) return -1;
        return diff;
    }
};