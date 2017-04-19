class ATOI {
    string strip(string s) {
        int i = 0;
        for (; i < s.length(); ++i)
            if (s[i] != ' ')
                break;
        return s.substr(i, s.length());
    }

    bool containNonIntegerSymbol(string s) {
        if (*s.begin() == '+' || *s.begin() == '-') {
            for (string::iterator it = s.begin() + 1; it != s.end(); ++it)
                if ((int) (*it) < int('0') || (int) *it > int('9'))
                    return true;
        } else
            for (string::iterator it = s.begin(); it != s.end(); ++it)
                if ((int)(*it) < int('0') || (int)*it > int('9'))
                    return true;
        return false;
    }

public:
    int myAtoi(string s) {
        stack<int> ret;
        int retV = 0;

        if (s.empty())
            return 0;
        if (containNonIntegerSymbol(s))
            return 0;
        if (s == "+" || s == "-")
            return 0;
        else if (*s.begin() == '+') {
            for (int i = 1; i < s.length(); ++i)
                ret.push(((int) s[i] - (int)'0'));
            int i = 0;
            while(ret.size() > 0) {
                retV += ret.top() * (int) pow(10, i++);
                ret.pop();
            }
        } else if (*s.begin() == '-') {
            for (int i = 1; i < s.length(); ++i)
                ret.push(((int) s[i] - (int)'0'));
            int i = 0;
            while(ret.size() > 0) {
                retV += ret.top() * (int) pow(10, i++);
                ret.pop();
            }
            retV *= -1;
        } else {
            for (string::iterator it = s.begin(); it != s.end(); ++it)
                ret.push((int)*it - (int)'0');
            int i = 0;
            while(ret.size() > 0) {
                retV += ret.top() * pow(10, i++);
                ret.pop();
            }
        }

        return retV;
    }
};
