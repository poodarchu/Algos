class Solution {
//TODO: fix value overflow    
  string strip(string s) {
		int i = 0;
		for (; i < s.length(); ++i)
			if (s[i] != ' ')
				break;
		return s.substr(i, s.length());
	}

	string containNonIntegerSymbol(string s) {
		if (*s.begin() == '+' || *s.begin() == '-') {
			for (int i = 1; i < s.length(); ++i)
				if ((int)s[i] >= int('0') && (int)s[i] <= int('9'))
					continue;
				else
					return s.substr(0, i);
		} else
			for (int i = 0; i < s.length(); ++i)
				if ((int)s[i] >= int('0') || (int)s[i] <= int('9'))
					continue;
				else
					return s.substr(0, i);

		return s;
	}

public:
	int myAtoi(string s) {
		stack<int> ret;
		int retV = 0;

		s = strip(s);
		s = containNonIntegerSymbol(s);

		if (s.empty())
			return 0;
	//    if (s = containNonIntegerSymbol(s))
	//        return 0;
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
