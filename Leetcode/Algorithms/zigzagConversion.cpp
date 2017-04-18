class Solution {
public:
    string convert(string s, int numRows) {
        if (s.length() <= numRows || numRows == 1)
            return s;

        string *output = new string[numRows];
//        string* output = (string* )malloc(numRows* sizeof(string));
//        memset(output,0,sizeof(output));
        int lengthOfGroup = 2*numRows - 2;

        int curr = 0;
        while ( curr < s.length() ) {
            for (int row = 0; row < numRows; ++row) {
                int currentRow = row;
                while(currentRow < lengthOfGroup && (curr+currentRow) < s.length()) {
                    output[row] += s[curr + currentRow];
                    if ((2*(numRows-row) - 2) > 0)
                        currentRow += 2*(numRows-row) - 2;
                    else
                        break;
                }
            }
            curr += lengthOfGroup;
        }

        string ret;
        for (int i = 0; i < numRows; ++i)
            ret += output[i];

        return ret;
    }
};
