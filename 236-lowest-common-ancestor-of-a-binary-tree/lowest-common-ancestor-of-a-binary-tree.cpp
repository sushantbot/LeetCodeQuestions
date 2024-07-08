/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //Base cases
        //agar root null hua to null return krenge 
        if(root==nullptr){
            return nullptr;
        }
        //agar root aur p equal hua to p return krenge
        if(root->val==p->val){
            return p;
        }
        //agar root aur q equal hua to q return krenge
        if(root->val==q->val){
            return q;
        }

        //Now we will call recursion 
        TreeNode*leftSubtree=lowestCommonAncestor(root->left,p,q);
        TreeNode*rightSubtree=lowestCommonAncestor(root->right,p,q);


        //Now we will compare with the left and right of the subtree
        //jab dono side null ho to null hi return krenge
        if(leftSubtree==nullptr && rightSubtree==nullptr){
            return NULL;
        }
        //agar ek null ho dusra non null ho to non null wale ko return krenge
        else if(leftSubtree!=nullptr && rightSubtree==nullptr){
            return leftSubtree;
        }
        else if(leftSubtree==nullptr && rightSubtree!=nullptr){
            return rightSubtree;
        }
        //agar iss sab me se kch bhi nhi hai to sirf ek case bachta hai 
        //wo ye ki left aur right subtree dono non null hai 
        //aur iss case me root ko return krenge
        else{
            return root;
        }



    }
};