/* https://www.acmicpc.net/problem/18809 */

/*
	다음의 부분 문제로 나누어 해결한다.
	1. 초기에 배양액을 둘 곳을 순열로 결정한다.
	2. 배양액으로부터 BFS를 돌며 색깔이 다른 배양액이 동시에 만났을 때에 대한 처리를 고려한다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

struct Node {
	int y, x, color;
	Node(int _y, int _x, int _c) : y(_y), x(_x), color(_c) {}
};

int N, M, G, R, board[50][50], simul_board[50][50], sec_board[50][50], ans = 0;
vector<Node> initQ;

void simul() {
	memset(simul_board, 0, sizeof(simul_board));
	memset(sec_board, 0, sizeof(sec_board));
	queue<Node> Q;

	for (auto it : initQ) {
		Q.push(it);
		simul_board[it.y][it.x] = it.color;
	}

	int cnt = 0;
	while (!Q.empty()) {
		Node cur = Q.front(); Q.pop();
		if (simul_board[cur.y][cur.x] == 'f') continue;

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny < 0 || ny == N || nx < 0 || nx == M || board[ny][nx] == 0)
				continue;

			if (simul_board[ny][nx] == 0) {
				simul_board[ny][nx] = cur.color;
				sec_board[ny][nx] = sec_board[cur.y][cur.x] + 1;
				Q.push(Node(ny, nx, cur.color));
			}
			else {
				if (simul_board[ny][nx] != cur.color &&
					simul_board[ny][nx] != 'f' &&
					sec_board[ny][nx] == sec_board[cur.y][cur.x] + 1) {
					simul_board[ny][nx] = 'f';
					cnt++;
				}
			}
		}
	}
	ans = max(ans, cnt);
}

void plant(int y, int x, int g, int r) {
	if (g == 0 && r == 0)
		simul();
	else {
		for (int i = y; i < N; i++) {
			for (int j = x; j < M; j++) {
				if (board[i][j] == 2) {
					if (g > 0) {
						initQ.push_back({ i, j, 'g' });
						plant(i, j + 1, g - 1, r);
						initQ.pop_back();
					}
					if (r > 0) {
						initQ.push_back({ i, j, 'r' });
						plant(i, j + 1, g, r - 1);
						initQ.pop_back();
					}
				}
			}
			x = 0;
		}
	}
}


int main() {
	cin >> N >> M >> G >> R;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	plant(0, 0, G, R);

	cout << ans << '\n';
}