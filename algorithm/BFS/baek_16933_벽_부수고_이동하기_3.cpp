/* https://www.acmicpc.net/problem/16933 */

/*
	BOJ의 14442 벽 부수고 이동하기 2 문제와 맥락은 같다.
	https://github.com/qhcjfdudn/algorithm_study/blob/master/algorithm/BFS/baek_14442_%EB%B2%BD_%EB%B6%80%EC%88%98%EA%B3%A0_%EC%9D%B4%EB%8F%99%ED%95%98%EA%B8%B0_2.cpp
	벽을 낮에만 부술 수 있다는 조건이 추가되었다.
	매번 움직일 때마다 낮과 밤은 바뀌니, BFS 과정 중 노드의 변수에 현재 까지의 거리를 저장하면
	홀수일 때는 낮, 짝수일 때는 밤일 것이다. 가만히 기다려도 이동을 한 것으로 치기 때문이다.
	따라서 visited의 조건으로 낮/밤을 추가해주고, 노드의 거리 값으로 가능 여부를 확인해주면 될 것이다.
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
bool visited[2][11][1002][1002]; // [낮/밤][K][Y][X]

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

			// 벽을 부수려고 한다면, 현재는 낮이어야 한다
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

		// 현재가 밤이라면, 주변에 벽이 있든 없든, 가만히 기다리는 것을 포함해준다. 주변에 벽이 없을 때
		// 기다릴 필요가 없지만, 논리에 어긋나는 부분은 없다. 최적의 답이 언젠가 한 번 기다려야 한다면,
		// 현재부터 최적의 답 사이에서 어쨌든 1번은 기다려야 하기 때문이다.
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