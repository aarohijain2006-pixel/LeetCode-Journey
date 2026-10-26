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
    bool findPath(TreeNode* root, int targetSum, int currSum){
        if(root == NULL){
            return false;
        }
        currSum += root->val;
        if(currSum == targetSum && root->left == NULL && root->right == NULL){
            return true;
        }
        if(findPath(root->left, targetSum, currSum) || findPath(root->right, targetSum, currSum)){
            return true;
        }
        currSum -= root->val;
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return findPath(root, targetSum, 0);
    }
};