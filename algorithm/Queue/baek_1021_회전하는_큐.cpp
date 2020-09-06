/* https://www.acmicpc.net/problem/1021 */

/*
	큐를 이용해서 타깃까지 이동 후, 좌/우 중 어느 쪽에서 오는 게 나은지
	판별하여 답을 구할 수 있다.
*/

#include <iostream>
#include <queue>
using namespace std;

int N, M, ans, num;
deque<int> DQ;

void init() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		DQ.push_back(i);
}

int cntMv(int n) {
	int cnt = 0;
	while (DQ.front() != n) {
		DQ.push_back(DQ.front());
		DQ.pop_front();
		cnt++;
	}
	DQ.pop_front();

	return min(N - cnt, cnt);
}

int main() {
	init();

	while (M--) {
		cin >> num;
		ans += cntMv(num);
		N--;
	}

	cout << ans << '\n';
}