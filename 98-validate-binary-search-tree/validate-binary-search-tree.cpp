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
    bool Solve(TreeNode*root,long long int lb,long long int ub){
        if(root==NULL){
            return true;
        }

        bool rootConditionCheck = (root->val < ub && root->val >lb);
        bool leftAns = Solve(root->left,lb,root->val);
        bool rightAns = Solve(root->right,root->val,ub);

        //now finally return ans
        return (rootConditionCheck && leftAns && rightAns);
    }
    bool isValidBST(TreeNode* root) {
        long long int lb =  -2147483657;  
        long long int ub = 2147483657;

        //passing these range into function 
        return Solve(root,lb,ub);

    }
};