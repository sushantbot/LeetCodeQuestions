/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode*& root) {
        // Using recursion to find the height of the tre
        if (root == nullptr) {
            return 0;
        }

        // solving 1 case myself
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int height = max(leftHeight, rightHeight) + 1;

        return height;
    }
    bool isBalanced(TreeNode* root) {
        // Agar root== null hai to balanced hi hoga
        if (root == nullptr) {
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);

        bool diffCheck = (diff <= 1);

        //recursive call
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(diffCheck && leftAns && rightAns){
            return true;
        }
        else{
            return false;
        }
    }
};