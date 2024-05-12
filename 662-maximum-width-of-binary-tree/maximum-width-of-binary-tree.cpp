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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int ans = 0;

        while(!q.empty())
        {
            int leftMost, rightMost;
            int currMin = q.front().second;
            int len = q.size();

            for(int i = 0; i < len; i++)
            {

                TreeNode* node = q.front().first;
                long long col = q.front().second - currMin;
                q.pop();

                if(i == 0)
                    leftMost = col;
                if(i == len - 1)
                    rightMost = col;

                if(node->left)
                    q.push({node->left, col * 2 + 1});

                if(node->right)
                    q.push({node->right, col * 2 + 2});

            }

            ans = max(ans, rightMost - leftMost + 1);

        }

        return ans;
    }
};