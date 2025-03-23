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
        if(root==p){
            return p;
        }
        if(root==q){
            return q;
        }

        TreeNode*leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode*rightAns = lowestCommonAncestor(root->right,p,q);

        //Now there are 3 cases for this question 

        if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else if (leftAns != NULL && rightAns == NULL ){
            return leftAns;
        }
        else if(leftAns == NULL && rightAns == NULL){
            return NULL;
        }
        else{
            //this case is when both are non null, return root;
            return root;
        }
    }
};