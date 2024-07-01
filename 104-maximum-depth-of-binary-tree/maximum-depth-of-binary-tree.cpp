
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
    int Approach1(TreeNode*&root) {
        queue<TreeNode*> q;
        if (root == nullptr) {
            return 0;
        }
        q.push(root);
        q.push(nullptr);
        int Level = 1;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == nullptr) {
                Level++;
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                if (front->left != nullptr) {
                    q.push(front->left);
                }
                if (front->right != nullptr) {
                    q.push(front->right);
                }
            }
        }
        return Level - 1;
    }
    int Approach2(TreeNode*&root){
        if(root==nullptr){
            return 0;
        }

        //Now using recursion to find the height
        int leftHeight=Approach2(root->left);
        int rightHeight=Approach2(root->right);
        //Now we will take the maximum of left and right
        // subtree and store it in the height
        int height=max(leftHeight,rightHeight)+1;
        return height;
    }
    int maxDepth(TreeNode* root) {
        // return Approach1(root);
        return Approach2(root);
    }
};