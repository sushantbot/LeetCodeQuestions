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
    bool solve(TreeNode* &root, int targetSum,int sum){
        if(root==nullptr){
            return false;
        }
        sum+=root->val;
        if(root->left==nullptr&& root->right==nullptr){
            //we are at the leafNode and need to verify the sum with targetSum
            if(sum==targetSum){
                return true;
            }
            else
                return false;
        }
        bool leftKaAns=solve(root->left,targetSum,sum);
        bool rightKaAns=solve(root->right,targetSum,sum);

        return leftKaAns || rightKaAns;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool finalans=solve(root,targetSum,sum);
        return finalans;
    }
};