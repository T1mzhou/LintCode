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


class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    
    static bool cmp(pair<int, int> firstValue, pair<int, int> secondValue)
    {
        return firstValue.second < secondValue.second;
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
        int start = 0;
        int end = numbers.size() - 1;
        vector<pair<int, int>> numsPair;

        for (int i = 0; i < numbers.size(); i++)
        {
            numsPair.push_back({i, numbers[i]});
        }

        sort(numsPair.begin(), numsPair.end(), cmp);

        while ( start < end )
        {
            if ( numsPair[start].second + numsPair[end].second > target )
            {
                end--;
            }
            else if ( numsPair[start].second + numsPair[end].second < target )
            {
                start++;
            }
            else
            {
                if ( numsPair[start].first > numsPair[end].first )
                {
                    swap(numsPair[start].first,  numsPair[end].first);
                }
                
                return { numsPair[start].first, numsPair[end].first };
            }
        }

        return { -1, -1 };

    }
};