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
    int height(TreeNode*root){
        //Base case
        if(root==NULL){
            return 0;
        }

        int option1 = height(root->left);
        int option2 = height(root->right);

        int finalans=max(option1,option2)+1;
        return finalans;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            //in this case we will consider it balanced
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight-rightHeight);

        bool currNodeAns = (diff<=1);
        bool leftKaAns = isBalanced(root->left);
        bool rightKaAns = isBalanced(root->right); 

        //these all three cases in bool need to be true at the same time
        if(currNodeAns && leftKaAns && rightKaAns){
            return true;
        }
        return false;

    }
};