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
     * @return: Preorder in ArrayList which contains node values.
     */
    void preorderTraversal(TreeNode *root, vector<int>& res)
    {
        if ( root == nullptr )
        {
            return;
        }

        res.push_back(root->val);
        
        preorderTraversal(root->left, res);
        preorderTraversal(root->right, res);
    }
     
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        
        preorderTraversal(root, res);

        return res;
    }
};

