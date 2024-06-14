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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int levelSize = q.size();
            vector<int> output;

            for(int i = 0; i < levelSize; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                output.push_back(front->val);

                if(front->left != NULL)
                    q.push(front->left);

                if(front->right != NULL)
                    q.push(front->right);
            }

            ans.push_back(output);
        }

        return ans;
    }
};