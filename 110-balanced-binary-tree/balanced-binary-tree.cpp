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
    int height(TreeNode*root){
        if(root==NULL){
            return 0;
        }

        int leftSubtree = height(root->left);
        int rightSubtree = height(root->right);

        //operation on recursive calls
        return max(leftSubtree,rightSubtree)+1; 
    }


    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int diff = abs(leftHeight-rightHeight);
        bool currNodeAns = (diff<=1);
        //there are three cases for this to be true
        //case 1  the left subtree should be height balanced
        bool leftAns = isBalanced(root->left);
        //case 2  the right subtree should be height balanced
        bool rightAns = isBalanced(root->right);
        //case 3  the diff = abs(leftHeight-rightHeight)<=1


        //now returning true iff the above three cases are true at the same time
        return (currNodeAns && leftAns && rightAns);       
    }
};