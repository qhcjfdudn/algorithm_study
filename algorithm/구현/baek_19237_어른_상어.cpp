/* https://www.acmicpc.net/problem/19237 */

/*
	단순히 brute force로 처리해도 문제는 해결하겠지만, 최적화를 위한 고민.
	1. 냄새가 만들어지고 k시간이 지난 후 사라질 때, 사라지는 냄새를 어떻게 찾을지?
	2. 상어의 리스트에서, 쫓겨나는 상어를 어떻게 없애고, 또는 리스트에 남기는 게 효율적일지?

	두 가지 모두 Queue를 통해 해결하였다.
	1. 냄새가 존재하는 곳을 요소로 갖는 Queue를 통해, 냄새가 사라져야 하는 시점에 없애준다.
	2. 요세푸스에서 힌트를 얻어, Queue를 통해 상어를 유지하고, 상어가 쫓겨나면 Queue에서 제거한다.

	그 외에는 단순 구현 문제.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int dy[5] = { 0, -1, 1, 0, 0 };
const int dx[5] = { 0, 0, 0, -1, 1 };

struct Smell {
	int y, x, t;
	Smell(int _y, int _x, int _t) : y(_y), x(_x), t(_t) {}
};

struct Shark {
	int num, y, x;
	Shark(int _n, int _y, int _x) : num(_n), y(_y), x(_x) {}
};

int N, M, K;
int curMoves[401], moves[401][5][5];
int board[20][20], smellBoard[20][20], tmpBoard[20][20];
queue<Smell> smellQ;
queue<Shark> sharkQ, tmpQ;

void init() {
	cin.sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				smellQ.push({ i, j, 0 });
				smellBoard[i][j]++;
				sharkQ.push({ board[i][j], i, j });
			}
		}
	}

	for (int i = 1; i <= M; i++) cin >> curMoves[i];
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				cin >> moves[i][j][k];
}

int go() {
	for (int times = 1; times <= 1000; times++) {
		// 상어 이동
		int sharkSize = sharkQ.size();
		for (int i = 0, ny, nx; i < sharkSize; i++) {
			bool moved = false;
			Shark cur = sharkQ.front(); sharkQ.pop();

			// 빈 곳 이동
			for (int j = 1; j <= 4 && !moved; j++) {
				ny = cur.y + dy[moves[cur.num][curMoves[cur.num]][j]];
				nx = cur.x + dx[moves[cur.num][curMoves[cur.num]][j]];
				if (ny < 0 || ny == N || nx < 0 || nx == N || board[ny][nx]) continue;

				curMoves[cur.num] = moves[cur.num][curMoves[cur.num]][j];
				if (tmpBoard[ny][nx] == 0) tmpBoard[ny][nx] = cur.num;
				else tmpBoard[ny][nx] = min(tmpBoard[ny][nx], cur.num);
				tmpQ.push({ tmpBoard[ny][nx], ny, nx });
				moved = true;
			}
			// 내 냄새 이동 - tmpBoard가 아닌 board에 바로 갱신
			for (int j = 1; j <= 4 && !moved; j++) {
				ny = cur.y + dy[moves[cur.num][curMoves[cur.num]][j]];
				nx = cur.x + dx[moves[cur.num][curMoves[cur.num]][j]];
				if (ny < 0 || ny == N || nx < 0 || nx == N || board[ny][nx] != cur.num) continue;

				curMoves[cur.num] = moves[cur.num][curMoves[cur.num]][j];
				smellBoard[ny][nx]++;
				smellQ.push({ ny, nx, times });
				sharkQ.push({ cur.num, ny, nx });

				moved = true;
			}
		}
		// 상어 go away와 함께 냄새 갱신
		while (!tmpQ.empty()) {
			Shark cur = tmpQ.front(); tmpQ.pop();
			if (tmpBoard[cur.y][cur.x] == cur.num) {
				tmpBoard[cur.y][cur.x] = 0;
				board[cur.y][cur.x] = cur.num;
				smellBoard[cur.y][cur.x]++;
				smellQ.push({ cur.y, cur.x, times });
				sharkQ.push(cur);
			}
		}

		// 냄새 지우기
		while (!smellQ.empty()) {
			if (times - smellQ.front().t == K) {
				Smell cur = smellQ.front(); smellQ.pop();
				if (--smellBoard[cur.y][cur.x] == 0)
					board[cur.y][cur.x] = 0;
			}
			else break;
		}

		if (sharkQ.size() == 1) return times;
	}
	return -1;
}

int main() {
	init();

	cout << go() << '\n';
}