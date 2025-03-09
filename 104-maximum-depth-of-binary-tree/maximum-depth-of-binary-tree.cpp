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
        if(root==nullptr){
            return 0;
        }

        //agar root null nahi hai to recursion se left aur right ke ans
        //NIkalenge

        int leftAns=maxDepth(root->left);
        int rightAns=maxDepth(root->right);

        int recAns = max(leftAns,rightAns)+1;
        return recAns;
    }
};