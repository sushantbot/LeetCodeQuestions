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
    void generateInorderArray(TreeNode* root,vector<int>&arr){
        if(root==NULL){
            return;
        }

        generateInorderArray(root->left,arr);
        //push the elements which are in N
        arr.push_back(root->val);
        generateInorderArray(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>vect;
        generateInorderArray(root,vect);
        //from function call above vect array has been generated
        //now check sum using binary search
        int start = 0;
        int end = vect.size()-1;
        while(start < end){
            int sum=vect[start]+vect[end]; 
            if(sum==k){
                return true;
            }
            else if(sum < k){
                start++;
            }else{
                //when sum>targetSum, end-- because end contains larger element
                end--;
            }
        }
        return false;
    
    }
};