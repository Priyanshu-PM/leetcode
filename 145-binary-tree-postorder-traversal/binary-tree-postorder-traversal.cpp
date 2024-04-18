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
    void postOrder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;

        postOrder(root->left, ans);
        postOrder(root->right, ans);
        ans.push_back(root->val);
    }    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // postOrder(root, ans);
        if(root == NULL)    return ans;
        stack<TreeNode*> st, r;
        st.push(root);

        while(!st.empty())
        {
            root = st.top();
            st.pop();
            r.push(root);

            if(root->left != NULL)
                st.push(root->left);
            if(root->right != NULL)
                st.push(root->right);
        }

        while(!r.empty())
        {
            ans.push_back(r.top()->val);
            r.pop();
        }

        return ans;
    }
};