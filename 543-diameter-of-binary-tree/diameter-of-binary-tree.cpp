/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    //Function declaration for finding the combined height
    int height(TreeNode*&root){
        if(root==nullptr){
            return 0;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int height=max(leftHeight,rightHeight)+1;
        return height;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        // first of all we will find the height of left
        int case1 = diameterOfBinaryTree(root->left);
        int case2 = diameterOfBinaryTree(root->right);
        int case3 = height(root->left)+height(root->right);

        //Our answer will be the max of the above three cases
        return max(case1,max(case2,case3));
    }
};