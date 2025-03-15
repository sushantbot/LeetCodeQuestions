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
    void Solve(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>temp,int sum){
        if(root==NULL){
            return;
        }
        //sum
        sum+=root->val;
        //push the root val to temp
        temp.push_back(root->val);
        //check if leaf node
        if(root->left==NULL && root->right==NULL){
            //verify if the sum == target sum
            if(sum==targetSum){
                ans.push_back(temp);
            }
            else{
                return;
            }
        }
        //Now recursive calls
        Solve(root->left,targetSum,ans,temp,sum);
        Solve(root->right,targetSum,ans,temp,sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //we will create 2d vector for storing 1d arrays
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        Solve(root,targetSum,ans,temp,sum);
        return ans;
    }
};