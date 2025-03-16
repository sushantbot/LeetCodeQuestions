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
    bool Solve(TreeNode*root,int targetSum,int sum){
                if(root==NULL){
            //tree DNE so return false
            return false;
        }
        sum+=root->val;
        if(root->left==NULL && root->right == NULL){
            if(sum==targetSum){
                return true;
            }
            return false;
        }

        //recursive call
        bool leftAns = Solve(root->left,targetSum,sum);
        bool rightAns = Solve(root->right,targetSum,sum);

        //now we will return true in the case if anyone of left and right is true

        return (leftAns || rightAns);



    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return Solve(root,targetSum,sum);
    }
};