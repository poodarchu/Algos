#include <iostream>
#include <string>

using namespace std;

void reverse(string& s, int head, int tail) {
	for (; head <= tail; head++, tail--) {
		char temp = s[head];
		s[head] = s[tail];
		s[tail] = temp;
	}
}

int main(int argc, char *argv[]) {
	string s;
	
	getline(cin, s);
	
	int head, tail;
	
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] != ' ' && s[i] != '\0') {
			head = i, tail = i;
			while(s[tail] != ' ' && s[tail] != '\0')
				tail++;
			tail -= 1;
			reverse(s, head, tail);
			head = tail;
			i = tail;
		}
	}
	
	cout << s;
}