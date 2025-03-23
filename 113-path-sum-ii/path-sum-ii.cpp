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
    void Solve(TreeNode* root, int targetSum,vector<vector<int>>&vect,vector<int>temp,int sum){
        //the vect is passed by reference we cause we need to keep track of
        //all the vectors which was passed before

        //the temp is passed by value so that it doesnot store the value of
        //previous calls

        if(root==NULL){
            return;
        }

        //we will add sum 
        sum+=root->val;
        temp.push_back(root->val);

        //we will check for leaf node
        if(root->left==NULL && root->right==NULL){
            if(targetSum==sum){
                //push the temp vector inside the 2-D vector
                vect.push_back(temp);
            }
        }

        //now recursive calls for left and right Subtree
        Solve(root->left,targetSum,vect,temp,sum);
        Solve(root->right,targetSum,vect,temp,sum);




    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>vect;    //the stored 1d vector will be pushed here
        vector<int>temp;    //this will be used to store path
        int sum = 0;
        Solve(root,targetSum,vect,temp,sum);
        return vect;
    }
};