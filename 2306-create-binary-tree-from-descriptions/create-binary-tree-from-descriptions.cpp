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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, int> parent;

        for(auto it: descriptions)
        {
            int p = it[0], c = it[1], isLeft = it[2];
            if(mp.count(p) == 0) {
                mp[p] = new TreeNode(p);
            }

            if(mp.count(c) == 0) {
                mp[c] = new TreeNode(c);
            }

            if(isLeft)  mp[p]->left = mp[c];
            else mp[p]->right = mp[c];

            parent[c] = p;
        }

        for(auto it: mp) {
            if(parent.find(it.first) == parent.end()) {
                return mp[it.first];
                break;
            }
        }
        return NULL;
    }
};