class Solution {
public:
    /**
     * @param a: an integer array
     * @return: nothing
     */
    void sortIntegers(vector<int> &a) {
        if ( a.empty() )
        {
            return ;
        }

        quickSort(a, 0, a.size() - 1);
    }

private:
    void quickSort(vector<int> &a, int start, int end)
    {
        if ( start >= end )
        {
            return ;
        }
        
        int left = start;
        int right = end;
        int pivot  = a[(start + end) / 2];

        while ( left <= right )
        {
            while ( left <= right && a[left] < pivot )
            {
                left++;
            }

            while ( left <= right && a[right] > pivot )
            {
                right--;
            }

            if ( left <= right )
            {
                swap(a[left], a[right]);
                left++;
                right--;
            }
        }

        quickSort(a, start, right);
        quickSort(a, left, end);
    }
};

