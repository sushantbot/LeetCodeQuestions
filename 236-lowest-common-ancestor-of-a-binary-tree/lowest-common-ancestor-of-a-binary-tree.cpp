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
        //Base Case
        if(root==nullptr){
            return nullptr;
        }
        //Agar root=p hua to p return krenge
        if(root->val==p->val){
            return p;
        }
        if(root->val==q->val){
            return q;
        }

        //now we will find leftkaAns and rightka ans
        TreeNode*LeftKaAns=lowestCommonAncestor(root->left,p,q);
        TreeNode*rightKaAns=lowestCommonAncestor(root->right,p,q);

        if(LeftKaAns == nullptr && rightKaAns == nullptr){
            //when both are null then we need to return null in this case
            return nullptr;
        }
        else if(LeftKaAns != nullptr && rightKaAns == nullptr){
            return LeftKaAns;
        }
        else if(LeftKaAns == nullptr && rightKaAns != nullptr){
            return rightKaAns;
        }
        else{
            //jab dono non null ho to root return krna hai 
            return root;
        }

    }
};