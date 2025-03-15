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
        // Base case of recursion
        if (root == NULL) {
            return NULL;
        }
        if (root == p) {
            return p;
        }
        if (root == q) {
            return q;
        }


        //Now recursive call and cases
        TreeNode*leftKaAns = lowestCommonAncestor(root->left,p,q);
        TreeNode*rightKaAns = lowestCommonAncestor(root->right,p,q);

        if(leftKaAns==NULL && rightKaAns!=NULL){
            return rightKaAns;
        }
        else if(leftKaAns!=NULL && rightKaAns==NULL){
            return leftKaAns;
        }
        else if(leftKaAns==NULL && rightKaAns==NULL){
            return NULL;
        }
        else{
            return root;
        }

        
    }
};