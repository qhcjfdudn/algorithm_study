/* https://www.acmicpc.net/problem/1516 */

/*
	위상정렬, DP 등으로 간단히 해결 가능한 문제. 임의의 건물을 짓기 위해 먼저 지어야 하는 것들 중
	가장 오래걸리는 값을 취하면 간단히 해결할 수 있다.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, cache[500], createTime[500];
vector<int> prerequisite[500];

int DP(int idx) {
	if (prerequisite[idx].empty()) return createTime[idx];

	int& ret = cache[idx];
	if (ret) return ret;

	for (auto it : prerequisite[idx])
		ret = max(ret, DP(it));

	return ret += createTime[idx];
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;
	for (int i = 0, a; i < N; i++) {
		cin >> createTime[i];
		while (1) {
			cin >> a;
			if (a == -1) break;
			prerequisite[i].push_back(a - 1);
		}
	}

	for (int i = 0; i < N; i++)
		cout << DP(i) << '\n';
}