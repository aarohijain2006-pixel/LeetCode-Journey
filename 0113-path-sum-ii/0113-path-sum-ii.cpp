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
    void findPath(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& path, int sum){
        if(root == NULL) return;

        path.push_back(root->val);
        sum += root->val;

        if(root->left == NULL && root->right == NULL){
            if(sum == targetSum){
                ans.push_back(path);
            }
        }
        findPath(root->left, targetSum, ans, path, sum);
        findPath(root->right, targetSum, ans, path, sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>path;
        int sum = 0;
        findPath(root, targetSum, ans, path, sum);
        return ans;
    }
};