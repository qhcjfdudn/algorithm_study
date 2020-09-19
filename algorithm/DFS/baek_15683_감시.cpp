/* https://www.acmicpc.net/problem/15683 */

/*
	감시하고자 하는 방향을 상수화하여 인덱싱으로 한 번에 찾을 수 있도록 구현.
	watching 함수를 set, unset함으로 중복 감시되며 개수가 세어지는 것을 방지.
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int rotateCnt[6] = { 0, 4, 2, 4, 4, 1 };
const int dirTable[6][4][4]{
	{},
	{ { 1, 0, 0, 0 }, { 0, 1, 0, 0 }, { 0, 0, 1, 0 }, { 0, 0, 0, 1 } },
	{ { 1, 0, 1, 0 }, { 0, 1, 0, 1 }, {}, {} },
	{ { 1, 1, 0, 0 }, { 0, 1, 1, 0 }, { 0, 0, 1, 1 }, { 1, 0, 0, 1 } },
	{ { 1, 1, 1, 0 }, { 0, 1, 1, 1 }, { 1, 0, 1, 1 }, { 1, 1, 0, 1 } },
	{ { 1, 1, 1, 1 }, {}, {}, {} }
};
const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { 1, 0, -1, 0 };

struct CCTV {
	int num, y, x;
	CCTV(int _n = -1, int _y = -1, int _x = -1) : num(_n), y(_y), x(_x) {}
};

int N, M, board[10][10], cctvCnt, wallCnt;
CCTV cctv[8];

void init() {
	cin >> N >> M;
	for (int i = 0; i < N + 2; i++) board[i][0] = board[i][M + 1] = -1;
	for (int i = 0; i < M + 2; i++) board[0][i] = board[N + 1][i] = -1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 6) {
				board[i][j] = -1;
				wallCnt++;
			}
			else if (board[i][j] > 0) {
				cctv[cctvCnt] = { board[i][j], i, j };
				cctvCnt++;
				board[i][j] = 10;
			}
		}
	}
}

int watching(int cIdx, int d, int delta) {
	int cnt = 0;

	for (int i = 0, y, x; i < 4; i++) {
		if (dirTable[cctv[cIdx].num][d][i]) {
			y = cctv[cIdx].y + dy[i];
			x = cctv[cIdx].x + dx[i];
			while (board[y][x] != -1) {
				if (board[y][x] == 0) cnt++;
				board[y][x] += delta;
				y += dy[i];
				x += dx[i];
			}
		}
	}

	return cnt;
}

int DFS(int cctvIdx, int cnt) {
	if (cctvIdx == cctvCnt) return cnt;
	else {
		int ret = 0;
		for (int i = 0, delta; i < rotateCnt[cctv[cctvIdx].num]; i++) {
			delta = watching(cctvIdx, i, 1);
			ret = max(ret, DFS(cctvIdx + 1, cnt + delta));
			watching(cctvIdx, i, -1);
		}
		return ret;
	}
}

int solve() {
	return N * M - wallCnt - cctvCnt - DFS(0, 0);
}

int main() {
	init();
	cout << solve() << '\n';
}