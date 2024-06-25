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
    void inOrder(TreeNode* root, vector<int>& ls)
    {
        if(!root)   return;
        inOrder(root->left, ls);
        ls.push_back(root->val);
        inOrder(root->right, ls);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        
        if(!root)   return NULL;
        vector<int> ls;
        inOrder(root, ls);

        unordered_map<int, int> mp;
        int n = ls.size();
        for(int i = n-1; i >= 0; i--) {
            if(i < n-1) {
                mp[ls[i]] = mp[ls[i+1]] + ls[i];
            }
            else {
                mp[ls[i]] = ls[i];
            }
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) 
        {
            TreeNode* node = q.front();
            q.pop();
            node->val = mp[node->val];
            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return root;
    }
};