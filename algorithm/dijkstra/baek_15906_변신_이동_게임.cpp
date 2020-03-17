/* https://www.acmicpc.net/problem/15906 */

/*
	다익스트라 최단거리 알고리즘을 적용해야 하는 문제.
	일반 모드와 변신 모드에 대해 서로 다른 dist를 적용해야 함을
	깨달아야 문제를 해결할 수 있다.
	어떤 위치에 일반 모드로 먼저 도달했을 때, 도달한 위치로부터 나아가는 변신 모드의
	턴 수는 t를 더한 계산이 되지만, 변신 모드로 먼저 도달했을 경우 t를 더하지 않기 때문에
	일반 모드와 변신 모드의 움직임을 따로 계산 해야 한다.
*/

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

struct Node {
	int cnt, y, x;
	bool charge;
	Node(int _cnt, int _y, int _x, bool _c) : cnt(_cnt), y(_y), x(_x), charge(_c) {}
	bool operator < (const Node &rhs) const {
		return cnt > rhs.cnt;
	}
};

int N, t, r, c;
string board[500];
int dist[2][500][500];
bool visited[2][500][500];

int solve() {
	priority_queue<Node> PQ;

	PQ.push({ 0, 0, 0, false });

	while (!PQ.empty()) {
		Node cur = PQ.top(); PQ.pop();
		if (cur.y == r && cur.x == c) return cur.cnt;
		if (visited[cur.charge ? 1 : 0][cur.y][cur.x]) continue;
		visited[cur.charge ? 1 : 0][cur.y][cur.x] = true;

		for (int i = 0; i < 4; i++) {
			int ny = cur.y, nx = cur.x;
			bool overBounds = false;
			while (!overBounds) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || ny == N || nx < 0 || nx == N) overBounds = true;
				if (!overBounds && board[ny][nx] == '#') break;
			}
			if (overBounds || visited[1][ny][nx] || dist[1][ny][nx] <= cur.cnt + (cur.charge ? 0 : t) + 1) continue;
			PQ.push({ cur.cnt + (cur.charge ? 0 : t) + 1, ny, nx, true });
			dist[1][ny][nx] = cur.cnt + (cur.charge ? 0 : t) + 1;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || ny == N || nx < 0 || nx == N || visited[0][ny][nx] || dist[0][ny][nx] <= cur.cnt + 1) continue;
			PQ.push({ cur.cnt + 1, ny, nx, false });
			dist[0][ny][nx] = cur.cnt + 1;
		}
	}
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> t >> r >> c;
	for (int i = 0; i < N; i++) cin >> board[i];

	fill(dist[0][0], dist[2][0], 100000);

	r--, c--;
	cout << solve() << '\n';
}