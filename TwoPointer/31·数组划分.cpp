class Solution {
public:
    /**
     * @param nums: The integer array you should partition
     * @param k: An integer
     * @return: The index after partition
     */
    int partitionArray(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if ( nums[i] >= k )
            {
                return i;
            }
        }

        return nums.size();
    }
};



