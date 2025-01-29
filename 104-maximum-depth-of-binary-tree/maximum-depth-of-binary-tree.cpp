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
    int maxDepth(TreeNode* root) {
        // if (root == NULL) {
        //     return 0;
        // }

        // int leftAns = maxDepth(root->left);
        // int rightAns = maxDepth(root->right);
        // int height = max(leftAns, rightAns) + 1;
        // return height;
        if(root==nullptr){
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int count = 0;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (front == nullptr) {
                // if front is nullptr then we need to increase the count
                count++;
                if(!q.empty()){
                    //nullptr tabhi push krenge jab q empty nahi hoha
                    //agar q empty ho gya aur nullptr ko pass kr diye to
                    //infinite loop me fas jayega
                    q.push(nullptr);
                }
            }
            else{
                //we need to push the left and right nodes of the root node
                //for the further counting of the Levels
                if(front->left!=nullptr){
                    q.push(front->left);
                }
                if(front->right!=nullptr){
                    q.push(front->right);
                }
            }
        }
        return count;
    }
};