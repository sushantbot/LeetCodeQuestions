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
    int kthSmallest(TreeNode* root, int &k) {
        if(root==NULL){
            return -1;
        }
        // LNR
        int leftAns= kthSmallest(root->left,k);
        if(leftAns != -1){
            return leftAns;
        }

        k--;
        if(k==0){
            return root->val;
        }

        int rightAns = kthSmallest(root->right,k);
        //we have to return rightans always because left wont be returned if -1
        //so we have to return right even if it -1
        return rightAns;
    }
};