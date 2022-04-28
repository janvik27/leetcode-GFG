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
    vector<int> morrisInorder(TreeNode* root)
    {
        TreeNode* curr = root;
        vector<int> inorder;
        while(curr!=NULL)
        {
            if(!curr->left)
            {
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                //find predecessor
                TreeNode* prev = curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                    prev = prev->right;
                
                if(prev->right ==NULL)
                {
                    prev->right =curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr =curr->right;
                }
            }
        }
        return inorder;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder = morrisInorder(root);
        return inorder;
    }
};