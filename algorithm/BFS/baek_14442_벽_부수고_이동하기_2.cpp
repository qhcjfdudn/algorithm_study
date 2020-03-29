/* https://www.acmicpc.net/problem/14442 */

/*
	BOJ의 2206 벽 부수고 이동하기 문제와 맥락은 같다.
	https://github.com/qhcjfdudn/algorithm_study/blob/master/algorithm/BFS/baek_2206_%EB%B2%BD_%EB%B6%80%EC%88%98%EA%B3%A0_%EC%9D%B4%EB%8F%99%ED%95%98%EA%B8%B0.cpp
	1개를 부술 수 있던 벽이 K개로 늘었다.
	기존의 벽을 부쉈는지, 부수지 않았는지 bool로 판단하던 정보를 K개 부쉈는지 아닌지로 판단하면
	나머지 로직은 모두 동일하다!
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
bool visited[11][1002][1002];

int solve() {
	if (N == 1 && M == 1) return 1;

	queue<Node> Q;
	Q.push({ 1, 1, 1, 0 });
	visited[0][1][1] = true;

	while (!Q.empty()) {
		Node cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (ny == N && nx == M) return cur.cnt + 1;
			if (board[ny][nx] == 0) continue; // 테두리일 경우
			if (board[ny][nx] == '1' && cur.distroy != K && !visited[cur.distroy + 1][ny][nx]) { // 부수자
				Q.push({ cur.cnt + 1, ny, nx, cur.distroy + 1 });
				visited[cur.distroy + 1][ny][nx] = true;
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

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> board[i] + 1; // 테두리를 패딩해주기 위해 한 칸 밀어 입력받는다

	// 테두리를 패딩해주어 차후 탐색을 편리하게 해준다
	for (int i = 0; i <= N; i++) board[i][M + 1] = board[N + 1 - i][0] = 0;
	for (int i = 0; i <= M; i++) board[0][i] = board[N + 1][M + 1 - i] = 0;

	cout << solve() << '\n';
}