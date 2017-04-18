class ZigZagConversion {
public:

    string convert(string s, int numRows) {
        if (s.length() <= numRows || numRows == 1)
            return s;

        string *output = new string[numRows];

        int lengthOfGroup = 2*numRows - 2;

        int curr = 0;
        while ( curr < s.length() ) {
            for (int row = 0; row < numRows; row++) {

                int currentIdx = row;

                if (s[curr+currentIdx] == '\0')
                    break;

                output[row] += s[curr + currentIdx];

                if ((2*(numRows-row) - 2) > 0) {
                    currentIdx += 2 * (numRows - row) - 2;
                    if (currentIdx < lengthOfGroup && (curr+currentIdx) < s.length())
                        output[row] += s[curr + currentIdx];
                }

            }
            curr += lengthOfGroup;
        }

        string ret = "";
        for (int i = 0; i < numRows; ++i)
            ret += output[i];

        delete[] output;

        return ret;
    }
};
