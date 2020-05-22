/* https://www.acmicpc.net/problem/10159 */

/*
	��� ������ ���踦 Ȯ���Ѵٰ� �����غ���. �÷��̵� �ͼ� �˰����� ����Ѵ�.
	�Է����κ��� ������ ���ſ�� ���, ������� ������ �ο��Ѵٰ� �������� �� �Ʒ��� ������ �� �ִ�.
	[i][[j] : [i][k], [k][j]�� ���� �����̶�� ��ȣ�� ���� ���̴�.
	����, [i][k] * [k][j] > 0�� ��쿡, �� ���� ����� Ȯ���ȴ�.
*/

#include <iostream>
using namespace std;

int N, M, dist[101][101];

void solve() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (dist[i][k] * dist[k][j] > 0)
					dist[i][j] = dist[i][k] + dist[k][j];
}

void printAns() {
	for (int i = 1, cnt; i <= N; i++) {
		cnt = 0;
		for (int j = 1; j <= N; j++)
			if (dist[i][j] == 0)
				cnt++;

		cout << cnt - 1 << '\n';
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0, a, b; i < M; i++) {
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = -1;
	}

	solve();

	printAns();
}