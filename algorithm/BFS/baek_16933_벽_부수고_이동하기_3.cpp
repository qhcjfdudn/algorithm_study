/* https://www.acmicpc.net/problem/16933 */

/*
	BOJ�� 14442 �� �μ��� �̵��ϱ� 2 ������ �ƶ��� ����.
	https://github.com/qhcjfdudn/algorithm_study/blob/master/algorithm/BFS/baek_14442_%EB%B2%BD_%EB%B6%80%EC%88%98%EA%B3%A0_%EC%9D%B4%EB%8F%99%ED%95%98%EA%B8%B0_2.cpp
	���� ������ �μ� �� �ִٴ� ������ �߰��Ǿ���.
	�Ź� ������ ������ ���� ���� �ٲ��, BFS ���� �� ����� ������ ���� ������ �Ÿ��� �����ϸ�
	Ȧ���� ���� ��, ¦���� ���� ���� ���̴�. ������ ��ٷ��� �̵��� �� ������ ġ�� �����̴�.
	���� visited�� �������� ��/���� �߰����ְ�, ����� �Ÿ� ������ ���� ���θ� Ȯ�����ָ� �� ���̴�.
*/

#include <iostream>
#include <queue>
using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

struct Node {
	int cnt, y, x, distroy;
	Node(int _c, int _y, int _x, int _d) : cnt(_c), y(_y), x(_x), distroy(_d) {}
};

int N, M, K;
char board[1002][1002];
bool visited[2][11][1002][1002]; // [��/��][K][Y][X]

int solve() {
	if (N == 1 && M == 1) return 1;

	queue<Node> Q;
	Q.push({ 1, 1, 1, 0 });
	visited[0][0][1][1] = true;

	while (!Q.empty()) {
		Node cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny == N && nx == M) return cur.cnt + 1;
			if (board[ny][nx] == 0) continue;

			// ���� �μ����� �Ѵٸ�, ����� ���̾�� �Ѵ�
			if (board[ny][nx] == '1' && (cur.cnt % 2) && cur.distroy != K
				&& !visited[(cur.cnt + 1) % 2][cur.distroy + 1][ny][nx]) {
				Q.push({ cur.cnt + 1, ny, nx, cur.distroy + 1 });
				visited[(cur.cnt + 1) % 2][cur.distroy + 1][ny][nx] = true;
			}
			else if (board[ny][nx] == '0' && !visited[(cur.cnt + 1) % 2][cur.distroy][ny][nx]) {
				Q.push({ cur.cnt + 1, ny, nx, cur.distroy });
				visited[(cur.cnt + 1) % 2][cur.distroy][ny][nx] = true;
			}
		}

		// ���簡 ���̶��, �ֺ��� ���� �ֵ� ����, ������ ��ٸ��� ���� �������ش�. �ֺ��� ���� ���� ��
		// ��ٸ� �ʿ䰡 ������, ���� ��߳��� �κ��� ����. ������ ���� ������ �� �� ��ٷ��� �Ѵٸ�,
		// ������� ������ �� ���̿��� ��·�� 1���� ��ٷ��� �ϱ� �����̴�.
		if (!(cur.cnt % 2) && !visited[(cur.cnt + 1) % 2][cur.distroy][cur.y][cur.x]) {
			Q.push({ cur.cnt + 1, cur.y, cur.x, cur.distroy });
			visited[(cur.cnt + 1) % 2][cur.distroy][cur.y][cur.x] = true;
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> board[i] + 1;

	for (int i = 0; i <= N; i++) board[i][M + 1] = board[N + 1 - i][0] = 0;
	for (int i = 0; i <= M; i++) board[0][i] = board[N + 1][M + 1 - i] = 0;

	cout << solve() << '\n';
}