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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        //if not we will be applying recursion here
        int option1 = height(root->left);
        int option2 = height(root->right);

        int heightt = max(option1,option2)+1;
        return heightt;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        //here we have 3 case
        // 1. Either our diameter is in left subtree
        int option1 = diameterOfBinaryTree(root->left);
        //Either out diameter is in right subtree
        int option2 = diameterOfBinaryTree(root->right);

        //3. it may be possible that out diameter is combination of left and right
        int option3 = height(root->left)+height(root->right);

        //But the answer would be the max of option 1 2 and 3
        int finalans = max(option1,max(option2,option3));
        return finalans;
    }
};