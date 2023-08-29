#include <iostream>

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
    bool result = 1;
    bool isValidBST(TreeNode* root) {
        ValidateBST(root, LLONG_MIN, LLONG_MAX);
        return result;
    }
    void ValidateBST(TreeNode* node, long int left, long int right) {
        if (node == NULL || result == 0) {
            return;
        }
        if (node->val >= right || node->val <= left) {
            result = 0;
            return;
        }
        ValidateBST(node->left, left, node->val);
        ValidateBST(node->right, node->val, right);
    }
};
