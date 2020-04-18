/* https://www.acmicpc.net/problem/1987 */

/*
	���ĺ��� �ߺ����� �ʰ� Ž���ؾ� �ϴµ�, ��θ� Ž���ϴ� �������� �ߺ��� �߻��� �� �ִ�.
	�̸� �����ϱ� ���� memoization�� �� �� �ִµ�, DP�� ����ϱ⿡�� [1 << 26][20][20]�� �ʹ� ū ������ �����Ѵ�.
	������ ������ ������ �������� ��, �ش� ��ġ�� ������ ������ �������� ��δ� ������ ���ѵ��� ���������� �� �� �ִ�.
	�̴� memoization�� �� ��δ� �� �� ���� �ʴµ�, �迭�� �����ϴ� ������ ���ϰ� ŭ�� �ǹ��Ѵ�.
	�̸� map�� ���� �ذ��� �� �ִ�. ������ �͵鸸 map���� �����ϸ�, backtrack�� �����ϴ�.
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