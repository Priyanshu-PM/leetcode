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


//  striver BST Iterator approach
class BSTIterator {
public:
    stack<TreeNode*> s;
    bool reverse = true;

    BSTIterator(TreeNode* root, bool isReverse) {
        
        reverse = isReverse;
        partialInorder(root);
    }
    
    void partialInorder(TreeNode* root){
        while(root != NULL){
            s.push(root);

            if(reverse == true)
                root = root->right;
            else
                root = root->left;
        }
    }
    
    int next() {
        TreeNode* top = s.top();
        s.pop();
        if(!reverse)      
            partialInorder(top->right);
        else
            partialInorder(top->left);
        return top->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

class Solution {

public:
    bool findTarget(TreeNode* root, int k) {
        
        if(!root)   return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i < j)
        {
            if(i + j == k)  return true;
            else if(i + j < k)  i = l.next();
            else    j = r.next();
        }

        return false;
    }
};