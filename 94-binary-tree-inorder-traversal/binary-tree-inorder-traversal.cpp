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

void inOrder(vector<int> &ans, TreeNode* root) {
    if(root == NULL) 
        return;

    inOrder(ans, root->left);
    ans.push_back(root->val);
    inOrder(ans, root->right);
}
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        if(root == NULL)    return {};
        stack<TreeNode*> st;
        while(root != NULL || !st.empty())
        {
            while(root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            res.push_back(root->val);

            root = root->right;
        }
        return res;

    }
};