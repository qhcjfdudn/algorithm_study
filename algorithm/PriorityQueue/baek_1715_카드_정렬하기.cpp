/* https://www.acmicpc.net/problem/1715 */

/*
	최소한으로 비교하기 위해서, 카드묶음의 수가 작은 것부터 비교해야 하는 것을
	증명해야 한다.

*/

#include <iostream>
#include <queue>
using namespace std;

int N, num;
priority_queue<int> PQ;

void init() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N;

	for (int i = 0, num; i < N; i++) {
		cin >> num;
		PQ.push(-num);
	}
}

int solve() {
	int ret = 0;
	for (int i = 1, a, b; i < N; i++) {
		a = PQ.top(); PQ.pop();
		b = PQ.top(); PQ.pop();
		ret += a + b;
		PQ.push(a + b);
	}
	return -ret;
}

int main() {
	init();

	cout << solve() << '\n';
}