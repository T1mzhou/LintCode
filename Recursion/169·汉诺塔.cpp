class Solution {
public:
    /**
     * @param n: the number of disks
     * @return: the order of moves
     */

    string move(char start, char end)
    {
        string res("from ");

        res.push_back(start);
        res.append(" to ");
        res.push_back(end);

        return res;
    }

    void towerOfHanoi(int n, char start, char end, char tmp, vector<string>& res)
    {
        if ( n == 1 )
        {
            res.push_back(move(start, end));
            return ;
        }

        towerOfHanoi(n - 1, start, tmp, end, res);
        res.push_back(move(start, end));
        towerOfHanoi(n - 1, tmp, end, start, res);
    }

    vector<string> towerOfHanoi(int n) {
        vector<string> res;

        towerOfHanoi(n, 'A', 'C', 'B', res);

        return res;
    }
};

