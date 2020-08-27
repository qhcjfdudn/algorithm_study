/* https://www.acmicpc.net/problem/16943 */

/*
	처음에는 하나하나 구현으로 해결할 수 있을 거라 예상했지만, 아니었다.
	같은 길이의 수에서 시작하는 숫자가 더 작을 때를 판단하는 것이 생각보다 복잡한 것.
	투포인터로 비교했어야 하나..
	그래서 결국 완탐!
	근데 next_permutation으로 구현한 소스가 백트래킹한 소스보다 빠르다. 왜지? 왜지??
*/

#include <iostream>
#include <algorithm>
using namespace std;

int A, B, ret = -1, len, sA[10];
bool visited[10];

void init() {
	while (A) {
		sA[len++] = A % 10;
		A /= 10;
	}
}

void solve(int idx, int v) {
	if (idx == len) {
		if (v <= B)
			ret = max(ret, v);
	}
	else {
		for (int i = 0; i < len; i++) {
			if (visited[i] || (idx == 0 && sA[i] == 0)) continue;
			visited[i] = true;
			solve(idx + 1, v * 10 + sA[i]);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> A >> B;

	init();

	solve(0, 0);
	cout << ret << '\n';
}