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
    bool checkSymmetry(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        if(left->val != right->val) return false;

        bool r1 = checkSymmetry(left->left, right->right);
        bool r2 = checkSymmetry(left->right, right->left);
        return r1 && r2;
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        if(root->left == NULL || root->right == NULL) return false;
        
        return checkSymmetry(root->left, root->right);
    }
};