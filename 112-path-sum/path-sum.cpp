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
    bool Solve(TreeNode* root,int sum, int targetSum){
        if(root==NULL){
            //Tree dne so return false
            return false;
        }
        sum += root->val;
        if(root->left==NULL && root->right==NULL){
            //this is leaf node and we need to check sum and target sum
            if(sum==targetSum){
                return true;
            }
            return false;
        }

        //Now recursive calls for left and right
        bool leftAns = Solve(root->left,sum,targetSum);
        bool rightAns = Solve(root->right,sum,targetSum);

        //dono ke answer ka or krenge
        //agar ek bhi true hai to true return krenge
        return leftAns || rightAns;


    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ans=Solve(root,sum,targetSum);
        return ans;
    }
};