/* https://www.acmicpc.net/problem/1092 */

/*
	실을 수 있는 횟수를 이진탐색으로 구하고,
	어떻게 실을지는 그리디하게 결정할 수 있다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, cranes[50], loads[10000];

void init() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> cranes[i];
	cin >> M;
	for (int i = 0; i < M; i++) cin >> loads[i];
	sort(cranes, cranes + N);
	sort(loads, loads + M);
}

bool canLoad(int times) {
	int mIdx = 0;
	for (int i = 0, cnt = 0; i < N; i++, cnt = 0) {
		while (mIdx < M && cnt < times) {
			if (loads[mIdx] <= cranes[i]) mIdx++, cnt++;
			else break;
		}
	}
	return mIdx == M;
}

int solve() {
	if (cranes[N - 1] < loads[M - 1]) return -1;

	int l = 1, r = M;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (canLoad(mid)) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}

int main() {
	init();

	cout << solve() << '\n';
}