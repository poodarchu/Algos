#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

bool comparator(const PII &p1, const PII &p2)
{
	if (p1.first != p2.first) {
		return p1.first < p2.first;
	}
	if (p1.second != p2.second) {
		return p1.second > p2.second;
	}
	return false;
}

int maxEnvelopes(vector<PII>& envelopes) {
	auto &a = envelopes;
	int n = a.size();
	sort(a.begin(), a.end(), comparator);
	
	vector<int> dp(n, 1);
	int i, j;
	int res = 0;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < i; ++j) {
			if (a[j].first >= a[i].first || a[j].second >= a[i].second) {
				continue;
			}
			dp[i] = max(dp[i], dp[j] + 1);
		}
		res = max(res, dp[i]);
	}
	dp.clear();
	
	return res;
}

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<PII> t;
	
	while(n--) {
		PII temp;
		cin >> temp.first >> temp.second;
		t.push_back(temp);
	}
	
	cout << maxEnvelopes(t);
}