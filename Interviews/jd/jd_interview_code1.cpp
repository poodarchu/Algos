题目：输入一个序列，用X表示小偷，＃表示普通人，0-9表示警察的能力值。
输出这个序列中可以背侦测到的小偷的数量。

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int numPeople;
	cin >> numPeople;

	string sequence;
	cin >> sequence;
	if (sequence.size() != numPeople)
		return -1;
	
//	bool* foundFlag = new bool[numPeople];
	vector<bool> foundFlag(numPeople);
	for (int h = 0; h < numPeople; h++) {
		foundFlag[h] = false;
	}
		
	for (int i = 0; i < sequence.size(); i++) {
		if (atoi(&sequence[i]) >= 0 && atoi(&sequence[i]) < 10) {
			int ability = atoi(&sequence[i]);
			for(int j = i-ability; j < i+ability; j++) {
				if (sequence[j] == 'X')
					foundFlag[j] = true;
			}
		} else if (sequence[i] == 'X' | sequence[i] == '#') {
			continue;
		} else {
			cout << "Unrecognized Symbol" << sequence[i] << endl;
			return -1;
		}
	}
	
	int count = 0;
	for (int k = 0; k < numPeople; k++) {
		if (foundFlag[k] == true)
			count++;
	}
	
	cout << count;
	
	return 0;
}