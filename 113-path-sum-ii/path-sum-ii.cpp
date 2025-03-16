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
    void Solve(TreeNode* root, int targetSum,vector<vector<int>>&ans,            vector<int>temp,int sum){
        if(root==NULL){
            return;
        }
        //now we will add sum
        sum+=root->val;
        temp.push_back(root->val);
        //now we will check for leaf node
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                ans.push_back(temp);
            }
        }
        
        //Now we will do the same work recursively for left and right subtree
        Solve(root->left,targetSum,ans,temp,sum);
        Solve(root->right,targetSum,ans,temp,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //we will be creating two vectors
        //one will be 2d vector and other will be 1d vector
        //one will store the path values and other will store the path

        vector<vector<int>>ans;
        vector<int>temp;
        int sum;

        //Now we will call vodi function 
        Solve(root,targetSum,ans,temp,sum);
        //solve function would have pushed all the path to ans array
        //return ans array
        return ans;
    }
};