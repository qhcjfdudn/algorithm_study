/* https://www.acmicpc.net/problem/3190 */

/*
	스네이크 게임 만들기!
	큐를 사용해 꼬리부터 차근차근 없애줄 수 있다.
*/

#include <iostream>
#include <queue>
using namespace std;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0, 1 };

struct Inst {
	int sec, dir;
	Inst(int _s, int _d) : sec(_s), dir(_d) {}
};

struct Pos {
	int y, x;
	Pos(int _y, int _x) : y(_y), x(_x) {}
};

int N, K, L, board[101][101];
queue<Inst> instQ;

void init() {
	cin >> N >> K;
	for (int i = 0, y, x; i < K; i++) {
		cin >> y >> x;
		board[y][x] = 2;
	}
	cin >> L;
	int s;
	char d;
	while (L--) {
		cin >> s >> d;
		instQ.push({ s, d == 'L' ? 1 : 3 });
	}
	instQ.push({ 100000, 0 });
}

int solve() {
	int curY = 1, curX = 1, curD = 3;
	int cnt = 0;
	queue<Pos> posQ;
	posQ.push({ 1, 1 });
	board[1][1] = 1;

	while (1) {
		int ny = curY + dy[curD];
		int nx = curX + dx[curD];
		if (ny == 0 || ny > N || nx == 0 || nx > N || board[ny][nx] == 1) break;
		if (board[ny][nx] == 0) {
			Pos p = posQ.front(); posQ.pop();
			board[p.y][p.x] = 0;
		}
		curY = ny, curX = nx;
		posQ.push({ ny, nx });
		board[ny][nx] = 1;
		cnt++;
		if (cnt == instQ.front().sec) {
			curD = (curD + instQ.front().dir) % 4;
			instQ.pop();
		}
	}
	return cnt + 1;
}

int main() {
	init();

	cout << solve() << '\n';
}