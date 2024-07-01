
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
    int maxDepth(TreeNode* root) {
        return Approach1(root);
    }
};