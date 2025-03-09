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
    // int maxDepth(TreeNode* root) {
    //     if(root==nullptr){
    //         return 0;
    //     }

    //     //agar root null nahi hai to recursion se left aur right ke ans
    //     //NIkalenge

    //     int leftAns=maxDepth(root->left);
    //     int rightAns=maxDepth(root->right);

    //     int recAns = max(leftAns,rightAns)+1;
    //     return recAns;
    // }

    int maxDepth(TreeNode*root){
        //we will be solving this question withthe help of queue
        //first we will create a queue
        if(root==NULL){
            //agar root null hai to fir hm 0 return kr denge
            return 0;
        }

        queue<TreeNode*>q;
        //for starting case we will push root and null
        q.push(root);
        q.push(nullptr);
        //we will run the queue till the queue is empty by itself
        int count=0;
        while(!q.empty()){
            //fetch the front element
            TreeNode* front_element=q.front();
            //we will pop the front element after storing it
            q.pop();

            if(front_element==nullptr){
                //we will increase the count
                count++;
                //again if the queue is not empty will push the nullptr
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
            else{
                //we will push the child of root if it is not null which is itself this case
                if(front_element->left!=nullptr){
                    q.push(front_element->left);
                }
                if(front_element->right!=nullptr){
                    q.push(front_element->right);
                }
            }
        }
        return count;


    }
};