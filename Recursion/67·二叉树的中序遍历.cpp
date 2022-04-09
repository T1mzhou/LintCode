/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */

     void inorderTraversal(TreeNode *root, vector<int>& res)
    {
        if ( root == nullptr )
        {
            return;
        }

        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        
        inorderTraversal(root, res);

        return res;
    }
};

