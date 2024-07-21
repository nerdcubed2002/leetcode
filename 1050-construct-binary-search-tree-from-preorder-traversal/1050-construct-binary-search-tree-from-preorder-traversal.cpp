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
    TreeNode* create(vector<int>&preorder,int ub,int &idx)
    {
        if(idx==preorder.size()||preorder[idx]>ub)
        return NULL;
        TreeNode* root=new TreeNode(preorder[idx]);
        idx++;
        root->left=create(preorder,root->val,idx);
        root->right=create(preorder,ub,idx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ub=INT_MAX;
        int idx=0;
        return create(preorder,ub,idx);
    }
};