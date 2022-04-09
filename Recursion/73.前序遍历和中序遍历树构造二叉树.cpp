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
     * @param preorder: A list of integers that preorder traversal of a tree
     * @param inorder: A list of integers that inorder traversal of a tree
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

    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd,
                        vector<int> &inorder, int inStart, int inEnd){
        
        if ( preStart > preEnd )
        {
            return nullptr;
        }

        if ( inStart > inEnd )
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int pos = findPos(inorder, preorder[preStart]);

        int leftLen = pos - inStart;
        int rightLen = inEnd - pos;


        root->left = buildTree(preorder, preStart + 1, preStart + leftLen,
                             inorder, inStart, pos - 1);
        root->right = buildTree(preorder, preEnd- rightLen + 1, preEnd,
                             inorder, pos + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

