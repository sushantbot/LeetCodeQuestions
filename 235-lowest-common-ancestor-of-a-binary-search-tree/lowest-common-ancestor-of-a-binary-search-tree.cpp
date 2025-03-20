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
        //case 2 when both the p and q are on same side
        if(p->val < root->val && q->val < root->val){
            //in this case we need to go inside the left subtree
            TreeNode*leftAns =  lowestCommonAncestor(root->left,p,q);
            return leftAns;
        }
        else if(p->val > root->val && q->val > root->val){
            TreeNode*rightAns = lowestCommonAncestor(root->right,p,q);
            return rightAns;
        }
        else if(p->val > root->val && q->val < root->val){
            // since both p and q are in different branches
            return root;
        }
        
        else if(p->val < root->val && q->val > root->val){
            // since both p and q are in different branches
            return root;
        }

        return root;

    }
};