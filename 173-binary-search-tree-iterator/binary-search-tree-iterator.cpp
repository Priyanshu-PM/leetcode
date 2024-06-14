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
class BSTIterator {

void inOrder(TreeNode* root, vector<int>& vec)
{
    if(root == NULL)    return;

    inOrder(root->left, vec);
    vec.push_back(root->val);
    inOrder(root->right, vec);
}

int start;
vector<int> vec;

public:
    BSTIterator(TreeNode* root) {
        
        inOrder(root, vec);
        start = 0;
    }
    
    int next() {
        
        if(start < vec.size())
            return vec[start++];

        return -1;
    }
    
    bool hasNext() {
        
        if(start < vec.size())
            return true;

        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */