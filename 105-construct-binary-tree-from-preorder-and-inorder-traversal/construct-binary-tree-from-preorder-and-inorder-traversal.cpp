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
    int SearchIndex(vector<int>& inorder, int target, int isize) {
        // we will search for the index
        for (int i = 0; i < isize; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* construction(vector<int>& preorder, vector<int>& inorder,
                           int &preorderIndex, int psize, int isize,
                           int inorderStart, int inorderEnd) {
        // Base Case
        if (preorderIndex >= psize || inorderStart > inorderEnd) {
            return nullptr;
        }

        // 1 case khudse solve krna hai
        int element = preorder[preorderIndex];
        preorderIndex++;
        TreeNode* root = new TreeNode(element);

        // now we will search for the index where the inorder will start
        // this is for the recursive call
        int position = SearchIndex(inorder, element, isize);

        // baake recursion sambhal lega
        root->left = construction(preorder, inorder, preorderIndex, psize,
                                  isize, inorderStart, position - 1);
        root->right = construction(preorder, inorder, preorderIndex, psize,
                                   isize, position + 1, inorderEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Approach
        // Sabse pehle N ko solve kr denge
        // uske baad left aur right ke liye recursive call maarenge
        // recursion saame kaam uske liye krega
        //
        int preorderIndex = 0;
        int psize = preorder.size();
        int isize = inorder.size();
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;

        // Calling function
        return construction(preorder, inorder, preorderIndex, psize, isize,
                            inorderStart, inorderEnd);
    }
};