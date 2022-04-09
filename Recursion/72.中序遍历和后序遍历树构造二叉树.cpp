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
     * @param inorder: A list of integers that inorder traversal of a tree
     * @param postorder: A list of integers that postorder traversal of a tree
     * @return: Root of a tree
     */
    int findPos(const vector<int> &inorder, int rootValue)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            if ( inorder[i] == rootValue )
            {
                return i;
            }
        }

        return 0;
    }

    TreeNode* buildTree(vector<int> &postorder, int postStart, int postEnd,
                        vector<int> &inorder, int inStart, int inEnd) {
        
        if ( postStart > postEnd )
        {
            return nullptr;
        }

        if ( inStart > inEnd )
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int pos = findPos(inorder, postorder[postEnd]);

        int leftLen = pos - inStart;
        int rightLen = inEnd - pos;


       root->left = buildTree(postorder, postStart, postStart + leftLen - 1,
                             inorder, inStart, pos - 1);
       root->right = buildTree(postorder, postEnd - rightLen, postEnd - 1,
                             inorder, pos + 1, inEnd );

        return root;
    }

    TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
         return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

