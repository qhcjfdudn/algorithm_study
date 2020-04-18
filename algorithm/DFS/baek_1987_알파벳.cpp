/* https://www.acmicpc.net/problem/1987 */

/*
	알파벳을 중복하지 않고 탐색해야 하는데, 경로를 탐색하는 과정에서 중복이 발생할 수 있다.
	이를 제거하기 위해 memoization을 할 수 있는데, DP를 사용하기에는 [1 << 26][20][20]은 너무 큰 공간을 차지한다.
	하지만 임의의 지점에 도달했을 때, 해당 위치에 도달할 때까지 지나오는 경로는 굉장히 제한됨을 직관적으로 알 수 있다.
	이는 memoization을 할 경로는 몇 개 되지 않는데, 배열로 선언하는 공간은 과하게 큼을 의미한다.
	이를 map을 통해 해결할 수 있다. 지나온 것들만 map으로 제외하면, backtrack이 가능하다.
*/

#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

struct Node {
	int y, x, visit, cnt;
	Node(int _y, int _x, int _v, int _c) : y(_y), x(_x), visit(_v), cnt(_c) {}
};

int R, C;
char board[20][21];
map<int, bool> map_board[20][20];

int max_cnt_alpha() {
	int ret = 1;
	stack<Node> ST;
	ST.push({ 0, 0, 1 << (board[0][0] - 65), 1 });

	while (!ST.empty()) {
		Node cur = ST.top(); ST.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 || ny == R || nx < 0 || nx == C || (cur.visit & (1 << (board[ny][nx] - 65))))
				continue;

			if (map_board[ny][nx][(cur.visit | (1 << (board[ny][nx] - 65)))]) continue;
			map_board[ny][nx][(cur.visit | (1 << (board[ny][nx] - 65)))] = true;

			ret = max(ret, cur.cnt + 1);
			ST.push({ ny, nx, (cur.visit | (1 << (board[ny][nx] - 65))), cur.cnt + 1 });
		}
	}
	return ret;
}

int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> board[i];

	cout << max_cnt_alpha() << '\n';
}