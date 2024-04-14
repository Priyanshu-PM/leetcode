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
    void solve(TreeNode* root, int &sum)
    {
        if(root == NULL)    return;
        if(root->left == NULL && root->right == NULL)   sum += root->val;
        
        solve(root->left, sum);
        if(root->right != NULL)
        {
            root = root->right;
            solve(root->left, sum);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if(root->left == NULL && root->right == NULL)   return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});
        while(!q.empty())
        {
            auto [node, leaf] = q.front();
            q.pop();
            if(leaf == 1)
            {
                if(node->left == NULL && node->right == NULL)
                    sum += node->val;
                else
                {
                    if(node->left)  q.push({node->left, 1});
                    if(node->right) q.push({node->right, 0});
                }
            }
            else
            {
                if(node->left)  q.push({node->left, 1});
                if(node->right) q.push({node->right, 0});
            }

        }
        // solve(root, sum);
        return sum;
    }
};