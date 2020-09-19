/* https://www.acmicpc.net/problem/2847 */

/*
	배열의 뒤에서부터 점점 작아지도록 구현
*/

#include <iostream>
using namespace std;

int N, scores[100];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> scores[i];
}

int solve() {
	int ret = 0;
	for (int i = N - 1; i > 0; i--) {
		if (scores[i - 1] < scores[i]) continue;
		ret += scores[i - 1] - scores[i] + 1;
		scores[i - 1] = scores[i] - 1;
	}
	return ret;
}

int main() {
	init();
	cout << solve() << '\n';
}