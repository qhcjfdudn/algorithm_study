/* https://www.acmicpc.net/problem/2206 */

/*
	벽을 부수고 이동하자.
	벽을 한 개 까지 부수고 이동할 수 있는데, 부순 상태와 부수지 않은 상태가 따로 관리 되어야 한다.
	왜냐하면 특정 지점에 벽을 부수고 도착한 상태와, 부수지 않고 도착한 상태의 이동 값이 다를 수 있고,
	또 상태에 따라서 앞으로 나아갈 수 있는 길도 달라지기 때문이다.
	하지만 BFS의 특성 상 어쨌든 현재 도착지점에 최초로 도달했을 때, 이는 최적이 보장되므로
	BFS 알고리즘을 이용하자!

	또, 시작지점이 종료지점일 수 있으므로, 알고리즘 상 예외가 되는지 여부를 판단하자.
*/

#include <iostream>
#include <queue>
using namespace std;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

struct Node {
	int cnt, y, x;
	bool distroy;
	Node(int _c, int _y, int _x, bool _d) : cnt(_c), y(_y), x(_x), distroy(_d) {}
};

int N, M;
char board[1002][1002];
bool visited[2][1002][1002];

int solve() {
	if (N == 1 && M == 1) return 1;

	queue<Node> Q;
	Q.push({ 1, 1, 1, false });
	visited[0][1][1] = true;

	while (!Q.empty()) {
		Node cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny == N && nx == M) return cur.cnt + 1;
			if (board[ny][nx] == 0) continue; // 테두리일 경우
			if (board[ny][nx] == '1' && !visited[1][ny][nx] && !cur.distroy) { // 부수자
				Q.push({ cur.cnt + 1, ny, nx, true });
				visited[1][ny][nx] = true;
			}
			else if (board[ny][nx] == '0' && !visited[cur.distroy][ny][nx]) { // 내 상태가 어떻든 여기는 길
				Q.push({ cur.cnt + 1, ny, nx, cur.distroy });
				visited[cur.distroy][ny][nx] = true;
			}
		}
	}
	return -1;
}

int main() {
	cin.sync_with_stdio(false); cin.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> board[i] + 1; // 테두리를 패딩해주기 위해 한 칸 밀어 입력받는다

	// 테두리를 패딩해주어 차후 탐색을 편리하게 해준다
	for (int i = 0; i <= N; i++) board[i][M + 1] = board[N + 1 - i][0] = 0;
	for (int i = 0; i <= M; i++) board[0][i] = board[N + 1][M + 1 - i] = 0;

	cout << solve() << '\n';
}