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
    int find(TreeNode *root,int &max_path)
    {
        if(root==NULL)return 0;
        int left=max(find(root->left,max_path),0);
        int right=max(find(root->right,max_path),0);
        max_path=max(max_path,left+right+root->val);
        return max(left,right)+root->val;
        
    }
    int maxPathSum(TreeNode* root) {
        int max_path=INT_MIN;
        find(root,max_path);
        return max_path;
    }
};