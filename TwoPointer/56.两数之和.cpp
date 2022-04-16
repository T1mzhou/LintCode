class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> hash;

        for (int i = 0; i < numbers.size(); i++)
        {
            int value = target - numbers[i];

            if ( hash.count(value) )
            {
                return { hash[value], i };
            }

            hash[numbers[i]] = i;
        }

        return { 0, 0 };
    }
};