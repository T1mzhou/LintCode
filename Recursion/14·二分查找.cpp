class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int start, int end, int target)
    {
        if ( start > end )
	    {
		    return -1;
	    }

	    int mid = start + (end - start) / 2;

	    if ( nums[mid] < target )
	    {
		    return binarySearch(nums, mid + 1, end, target);
	    }

	    if ( nums[mid] > target )
	    {
		    return binarySearch(nums, start, mid - 1, target);
	    }
	    
	    int tmp = binarySearch(nums, start, mid - 1, target);

	    if ( tmp != -1 )
	    {
		    return tmp;
	    }
	    
	    return mid;
    }

    int binarySearch(vector<int> &nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};

