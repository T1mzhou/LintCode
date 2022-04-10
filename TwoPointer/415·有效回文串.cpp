class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isValid(char str)
    {
	    return isdigit(str) || isalpha(str);
    }

    bool isEqual(char firstStr, char secondStr)
    {
	    return tolower(firstStr) == tolower(secondStr);
    }

    bool isPalindrome(string &s) {
        int left = 0;
	    int right = s.size() - 1;

	   while ( left < right )
	   {
		   while ( left < right && !isValid(s[left]) )
		   {
			   left++;
		   }

		   while ( left < right && !isValid(s[right]) )
		   {
			   right--;
		   }

		   while ( left < right && !isEqual(s[left], s[right]) )
		   {
			   return false;
		   }

		   left++;
		   right--;
	   }

	   return true;
    }
};

