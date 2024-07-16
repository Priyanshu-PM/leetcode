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
    bool findNode(TreeNode* root, int target, string &s)
    {
        if(root == NULL)    return false;
        if(root->val == target) return true;
        
        if(root->left) {
            s.push_back('L');
            if(findNode(root->left, target, s)) return true;
            s.pop_back();
        }

        if(root->right) {
            s.push_back('R');
            if(findNode(root->right, target, s)) return true;
            s.pop_back();
        }

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string left = "", right = "";
        findNode(root, startValue, left);
        findNode(root, destValue, right);

        int i = 0;
        int n = left.size(), m = right.size();
        int minLen = min(n, m);
        while(i < minLen) {
            if(left[i] == right[i]) i++;
            else break;
        }

        string ans = "";
        for(int j = 0; j < n - i; j++)    ans.push_back('U');

        ans = ans + right.substr(i, m - i);
        return ans;
    }
};