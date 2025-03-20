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
    // from this function i will be just storing my inorder traversal in array

    void inOrderTraversal(TreeNode*&root,vector<int>&arr){
        if(root==NULL){
            return;
        }
        //now call for left
        inOrderTraversal(root->left,arr);
        arr.push_back(root->val);
        inOrderTraversal(root->right,arr);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>arr;
        inOrderTraversal(root,arr);
        //Now the sorted arry has been created
        int i=-1;
        while(k!=0){
            k--;
            i++;
        }
        //when we are here k=0 and i is the required index;
        return arr[i];
    }
};