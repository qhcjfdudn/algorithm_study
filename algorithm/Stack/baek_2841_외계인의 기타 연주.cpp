/* https://www.acmicpc.net/problem/2841 */

/*
	외계인이 기타연주를 하는데, 굉장히 공감되는 문제.
	기타를 운지할 때의 고충은 외계인도 같은가보다.
*/

#include <iostream>
#include <stack>
using namespace std;

int N, T, ans;
stack<int> lines[7];

void init() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> T;
	for (int i = 1; i < 7; i++) lines[i].push(0);
}

int cntMv(int l, int p) {
	int ret = 0;
	while (lines[l].top() > p) {
		ret++;
		lines[l].pop();
	}
	if (lines[l].top() != p) {
		lines[l].push(p);
		ret++;
	}
	return ret;
}

int main() {
	init();

	for (int i = 0, line, pret; i < N; i++) {
		cin >> line >> pret;
		ans += cntMv(line, pret);
	}

	cout << ans << '\n';
}