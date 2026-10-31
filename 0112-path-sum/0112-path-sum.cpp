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
    void checkSum(TreeNode* root, int targetSum, int sum, bool& ans){
        if(root == NULL) return;
        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans = true;
                return;
            }
        }
        checkSum(root->left, targetSum, sum, ans);
        checkSum(root->right, targetSum, sum, ans);
        return ;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans = false;
        checkSum(root, targetSum, 0, ans);
        return ans;
    }
};