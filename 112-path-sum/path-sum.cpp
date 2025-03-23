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
    bool Solve(TreeNode* root, int targetSum,int Sum){
        if(root==NULL){
            return false;
        }
        Sum+=root->val;

        //check if leaf node
        if(root->left==NULL && root->right == NULL){
            if(Sum == targetSum){
                return true;
            }
            return false;
        }

        //then i will go into recursive calls
        bool leftAns = Solve(root->left,targetSum,Sum);
        bool rightAns = Solve(root->right,targetSum,Sum);

        return (leftAns || rightAns);


        //now what i will be doing is add the data of node till i get leaf and check with target sum when i get leaf, otherwise continue
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int Sum = 0;
        bool finalAns = Solve(root,targetSum,Sum);
        return finalAns;       
    }
};