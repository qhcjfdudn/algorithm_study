/* https://www.acmicpc.net/problem/15906 */

/*
	우선순위 큐를 사용해야 하는 BFS 문제.

*/

#include <iostream>
#include <string>
#include <queue>
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
bool visited[500][500];

int solve() {
	priority_queue<Node> PQ;
	PQ.push({ 0, 0, 0, false });

	while (!PQ.empty()) {
		Node cur = PQ.top(); PQ.pop();
		cout << cur.cnt << " " << cur.y << " " << cur.x << endl;
		if (cur.y == r && cur.x == c) return cur.cnt;
		if (visited[cur.y][cur.x]) continue;
		visited[cur.y][cur.x] = true;

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || ny == N || nx < 0 || nx == N || visited[ny][nx]) continue;
			PQ.push({ cur.cnt + 1, ny, nx, false });
		}
		for (int i = 0; i < 4; i++) {
			int ny = cur.y, nx = cur.x;
			bool overBounds = false;
			while (!overBounds) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || ny == N || nx < 0 || nx == N) overBounds = true;
				if (!overBounds && board[ny][nx] == '#') break;
			}
			if (overBounds || visited[ny][nx]) continue;
			PQ.push({ cur.cnt + (cur.charge ? 0 : t) + 1, ny, nx, true });
		}
	}
	return -1;
}

int main() {
	cin >> N >> t >> r >> c;
	for (int i = 0; i < N; i++) cin >> board[i];

	r--, c--;
	cout << solve() << '\n';
}
