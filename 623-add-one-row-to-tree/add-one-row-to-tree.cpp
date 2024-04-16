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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(root == NULL)    return new TreeNode(val);
        if(depth == 1)  //  for root level
        {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<pair<TreeNode*, int>> q;  //  node, level
        int level = 1;
        q.push({root, level});
        while(!q.empty())
        {
            int len = q.size();
            bool entered = false;

            for(int i = 0; i < len; i++)
            {
                auto it = q.front();
                TreeNode* node = q.front().first;
                level = q.front().second;
                q.pop();

                if(level == depth - 1)
                {
                    entered = true;
                    
                    TreeNode* temp1 = new TreeNode(val);
                    if(node->left != NULL)
                        temp1->left = node->left;
                    node->left = temp1;

                    TreeNode* temp2 = new TreeNode(val);
                    if(node->right != NULL)
                        temp2->right = node->right;
                    node->right = temp2;
                }
                else
                {
                    if(node->left)  q.push({node->left, level + 1});
                    if(node->right) q.push({node->right, level + 1});
                }
            }
            if(entered) return root;
        }
        return root;
    }
};