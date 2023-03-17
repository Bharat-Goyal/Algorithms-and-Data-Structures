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
//https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
class Solution {
public:
    int sumNumbers(TreeNode* root, int val = 0) {
        if(root == NULL) return 0;
        if(root->left==NULL and root->right==NULL) return root->val + val;
        return sumNumbers(root->left,  10*(root->val + val)) + sumNumbers(root->right, 10*(root->val + val));
    }
};
