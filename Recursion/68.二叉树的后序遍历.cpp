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
     * @return: Postorder in ArrayList which contains node values.
     */
     void postorderTraversal(TreeNode *root, vector<int>& res)
    {
        if ( root == nullptr )
        {
            return;
        }

        postorderTraversal(root->left, res);
        postorderTraversal(root->right, res);
	   res.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        
        postorderTraversal(root, res);

        return res;
    }
};

