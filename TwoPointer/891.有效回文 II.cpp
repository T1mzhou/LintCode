class Solution {
public:
    /**
     * @param s: a string
     * @return: whether you can make s a palindrome by deleting at most one character
     */

    pair<int, int> getFirstDifferenceIndex(const string& s, int left, int right)
    {
	    while ( left < right && s[left] == s[right] )
	    {
		   left++;
	       right--; 
	    }

	    pair<int, int> strPair = make_pair(left, right);
	    
	    return strPair;
    }
    
    bool isvalidPalindrome(const string& s, int left, int right)
    {
        pair<int, int> strPair = getFirstDifferenceIndex(s, left, right);

	    return strPair.first >= strPair.second;
    }
    
    bool validPalindrome(string &s) {

		pair<int, int> strPair = getFirstDifferenceIndex(s, 0, s.size() - 1);

	    if ( strPair.first >= strPair.second )
	    {
		    return true;
	    }

	    return isvalidPalindrome(s, strPair.first + 1, strPair.second) ||
	    		 isvalidPalindrome(s, strPair.first, strPair.second -1);
    }
};

