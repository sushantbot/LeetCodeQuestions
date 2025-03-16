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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }

        //Now recursive calls
        int leftSubtree = height(root->left);
        int rightSubtree = height(root->right);
        
        return max(leftSubtree,rightSubtree)+1;

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }

        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        int diff = abs(leftHeight-rightHeight);

        bool currNodeAns = (diff<=1);
        bool leftSubtree= isBalanced(root->left);
        bool rightSubtree= isBalanced(root->right);

        //When the all three cases of this bool functions return true
        return (currNodeAns && leftSubtree && rightSubtree);
    }
};