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
    int Sum(vector<int>&arr,int start,int end,int targetSum){
        int sum=0;
        while(start < end){
            sum = arr[start]+arr[end];
            if(sum==targetSum){
                return sum;
            }
            else if(sum < targetSum){
                start++;
            }else{
                //when sum>targetSum, end-- because end contains larger element
                end--;
            }
        }
        return sum;

    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        generateInorderArray(root,arr);
        //from function call above vect array has been generated
        //now check sum using binary search
        int finalSum  = Sum(arr,0,arr.size()-1,k);

        if(finalSum==k){
            return true;
        }
        else{
            return false;
        }


    }
};