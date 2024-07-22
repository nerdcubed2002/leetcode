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
    stack<TreeNode*> next, prev;

    void pushnext(TreeNode* root) {
        while (root) {
            next.push(root);
            root = root->left;
        }
    }

    void pushprev(TreeNode* root) {
        while (root) {
            prev.push(root);
            root = root->right;
        }
    }

    TreeNode* first() {
        if (next.empty()) return nullptr;
        TreeNode* node = next.top();
        next.pop();
        pushnext(node->right);
        return node;
    }

    TreeNode* last() {
        if (prev.empty()) return nullptr;
        TreeNode* node = prev.top();
        prev.pop();
        pushprev(node->left);
        return node;
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        pushnext(root);
        pushprev(root);

        TreeNode *i = first(), *j = last();
        while (i && j && i != j) {
            int sum = i->val + j->val;
            if (sum == k) return true;
            if (sum < k) i = first();
            else j = last();
        }
        return false;
    }
};