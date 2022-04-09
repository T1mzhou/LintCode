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
     * @param nums: an array
     * @return: the maximum tree
     */

    int findMaxValueIndex(vector<int>& nums, int start, int end)
    {   
        int maxValueIndex = start;

        for (int i = start + 1; i <= end; i++)
        {
            if ( nums[i] > nums[maxValueIndex] )
            {
                maxValueIndex = i;
            }
        }

        return maxValueIndex;
    }

    TreeNode* buildTree(vector<int>& nums, int start, int end)
    {
        if ( start > end )
        {
            return nullptr;
        }

        int pos = findMaxValueIndex(nums, start, end);

        TreeNode* root = new TreeNode(nums[pos]);
        root->left = buildTree(nums, start, pos - 1);
        root->right = buildTree(nums, pos + 1, end);

        return root;

    }


    TreeNode* constructMaximumBinaryTree(vector<int> &nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};

