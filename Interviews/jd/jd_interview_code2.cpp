题目：
在一个平面直角坐标系中，在原点又一个朝向 Y 轴正方向的发射装置
可以发射两发子弹，子弹可以穿墙
在第一象限有 n 个小车，小车的坐标为 X，长度为 L
输出可以射到的车的数量的最大值。

// 该问题可以抽象为：
// 有一个数组 M，求这个数组中的两个子数组 A 和 B，
// 这两个子数组要求某一时刻通过 Y 轴的数目最多，使得 A.size() + B.size() 最大。

#include <iostream>
#include <vector>

using namespace std;

struct Box {
	long X;
	long L;
};

int main(int argc, char *argv[]) {
	int numBoxes;
	cin >> numBoxes;
	
	vector<Box> boxSeq(numBoxes);
	
	
	long maxR = 0;
	for (int i = 0; i < numBoxes; i++) {
		cin >> boxSeq[i].X >> boxSeq[i].L;
		if ( (boxSeq[i].X+boxSeq[i].L) > maxR )
			maxR = boxSeq[i].X+boxSeq[i].L;
	}
	
//	cout << boxSeq[0].X << boxSeq[0].L;
	
//	vector<int> time(2);
	
//	int launchCount = 2;
	int count = 0;
	int max1 = 0, max2 = 0;
	long l, r;
	for (int t = 0; t < maxR; t++) {
		count = 0;
		for (int n = 0; n < numBoxes; n++) {
			l = boxSeq[n].X - t;
			r = boxSeq[n].X + boxSeq[n].L - t;
			if (l <= 0 && r >= 0)
				count++;
		}
		
		if (count > max1) {
			max1 = count;
			max2 = max1;
		} else if (count > max2) {
			max2 = count;
		} else
			continue;
	}
	
	cout << max1 + max2;
	
	return 0;
}