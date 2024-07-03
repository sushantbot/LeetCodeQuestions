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
        //Base Cases
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==p->val){
            return p;
        }
        if(root->val==q->val){
            return q;
        }

        //Solving one case myself
        TreeNode*LeftKaAns=lowestCommonAncestor(root->left,p,q);
        TreeNode*RightKaAns=lowestCommonAncestor(root->right,p,q);


        //Checking Cnditions
        if(LeftKaAns==nullptr && RightKaAns==nullptr){
            return nullptr;
        }
        else if(LeftKaAns!=nullptr && RightKaAns==nullptr){
            return LeftKaAns;
        }
        else if(LeftKaAns==nullptr && RightKaAns!=nullptr){
            return RightKaAns;
        }
        else{
            return root;
        }
    }
};