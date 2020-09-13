/* https://www.acmicpc.net/problem/11060 */

/*
	BFS Ž���� �ϸ� �� �Ǽ��ϴ� ��.
	�������� == ���������� ���� ó��
	����� ���ڤ�
*/

#include <iostream>
#include <queue>
using namespace std;

int N, board[1000], dist[1000];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> board[i];
}

int solve() {
	if (N == 1) return 0;

	queue<int> Q;
	Q.push(0);

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();

		for (int i = 1, next; i <= board[cur] && cur + i < N; i++) {
			next = cur + i;
			if (dist[next]) continue;
			if (next == N - 1) return dist[cur] + 1;
			dist[next] = dist[cur] + 1;
			Q.push(next);
		}
	}

	return -1;
}

int main() {
	init();

	cout << solve() << '\n';
}