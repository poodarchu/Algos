class Solution {
    string expandAroundCenter(string s, int left, int right) {
        int L = left, R = right;
        while (L >= 0 && R < s.length() && s.at(L) == s.at(R)) {
            L--;
            R++;
        }

        return s.substr(L+1, R-L-1);
    }
public:
    string longestPalindrome(string s) {
        int sLen = s.length();
        if (sLen == 0) return "";

        string lp = s.substr(0, 1);


        int start = 0, end = 0;
        for (int i = 0; i < s.length(); ++i) {
            string p1 = expandAroundCenter(s, i, i);
            if (p1.length() > lp.length())
                lp = p1;
            string p2 = expandAroundCenter(s, i, i+1);
            if (p2.length() > lp.length())
                lp = p2;
        }

        return lp;
    }
};
