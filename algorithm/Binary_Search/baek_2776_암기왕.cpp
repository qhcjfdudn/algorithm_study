/* https://www.acmicpc.net/problem/2776 */

/*
	이진탐색을 하며, 범위에서 오버플로우가 발생할 수 있음을 눈치채야 한다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int T, N, M, note1[1000000];

void preprocess() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> T;
}

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> note1[i];
	cin >> M;
	sort(note1, note1 + N);
}

int solve(int num) {
	int l = 0, r = N - 1;
	while (l <= r) {
		int mid = (r - l) / 2 + l;
		if (num < note1[mid]) r = mid - 1;
		else if (num > note1[mid]) l = mid + 1;
		else return 1;
	}
	return 0;
}

int main() {
	preprocess();

	while (T--) {
		init();
		for (int i = 0, num; i < M; i++) {
			cin >> num;
			cout << solve(num) << '\n';
		}
	}
}