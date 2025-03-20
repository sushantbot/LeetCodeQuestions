/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(root == p){
            return p;
        }
        if(root==q){
            return q;
        }

        //Now recursive calls for left and right subtree
        TreeNode* leftAns =lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns =lowestCommonAncestor(root->right,p,q);

        //Now three cases are possible
        //if both p and q are on the same side
        if(leftAns == NULL && rightAns == NULL){
            return NULL;
        }
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else{
            //this is the case when both left and right are non null
            return root;
        }


    }
};