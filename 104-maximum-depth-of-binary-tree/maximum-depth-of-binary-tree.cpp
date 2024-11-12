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
    int maxDepth(TreeNode* root) {
        //Base case
        if(root == NULL){
            return 0;
        }

        int leftkiHeight=maxDepth(root->left);
        int rightkiHeight=maxDepth(root->right);

        int ans= max(leftkiHeight,rightkiHeight);
        return ans+1;
    }
};