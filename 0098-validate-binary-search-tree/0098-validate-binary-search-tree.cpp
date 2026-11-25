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
    TreeNode* prev = NULL;

    void checkValid(TreeNode* root, int &galat){
        if(root == NULL) return;

        checkValid(root->left, galat);
        if(prev == NULL) prev = root;
        else{
            if(root->val <= prev->val){
                galat++;
                return;
            }
            prev = root;
        }
        checkValid(root->right, galat);
    }

    bool isValidBST(TreeNode* root) {
        int galat = 0;
        checkValid(root, galat);
        return galat == 0;
    }
};