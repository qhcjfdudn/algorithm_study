/* https://www.acmicpc.net/problem/1021 */

/*
	ť�� �̿��ؼ� Ÿ����� �̵� ��, ��/�� �� ��� �ʿ��� ���� �� ������
	�Ǻ��Ͽ� ���� ���� �� �ִ�.
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