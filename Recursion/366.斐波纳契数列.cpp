class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n, map<int, int>& memo)
    {
        if ( memo.count(n) != 0 )
        {
            return memo[n];
        }

        if ( n <= 2 )
        {
            return n - 1;
        }

        int res = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);

        memo.insert(pair<int, int>(n, res));

        return res;
    }

    int fibonacci(int n) {
        map<int, int> memo;

        return fibonacci(n, memo);
    }
};

