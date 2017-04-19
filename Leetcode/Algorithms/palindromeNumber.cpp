class PalindromeNumber {

#include <sstream>

public:
    bool isPalindrome(int x) {
        int temp = x>0 ? x:-x;
        stringstream ss;
        string s;

        ss << x;
        ss >> s;

        for (int i = 0; i < s.length()/2; i++)
            if (s[i] != s[s.length()-1-i])
                return false;

        return true;
    }
};
