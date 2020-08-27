/* https://www.acmicpc.net/problem/19237 */

/*
	�ܼ��� brute force�� ó���ص� ������ �ذ��ϰ�����, ����ȭ�� ���� ���.
	1. ������ ��������� k�ð��� ���� �� ����� ��, ������� ������ ��� ã����?
	2. ����� ����Ʈ����, �Ѱܳ��� �� ��� ���ְ�, �Ǵ� ����Ʈ�� ����� �� ȿ��������?

	�� ���� ��� Queue�� ���� �ذ��Ͽ���.
	1. ������ �����ϴ� ���� ��ҷ� ���� Queue�� ����, ������ ������� �ϴ� ������ �����ش�.
	2. �似Ǫ������ ��Ʈ�� ���, Queue�� ���� �� �����ϰ�, �� �Ѱܳ��� Queue���� �����Ѵ�.

	�� �ܿ��� �ܼ� ���� ����.
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
		// ��� �̵�
		int sharkSize = sharkQ.size();
		for (int i = 0, ny, nx; i < sharkSize; i++) {
			bool moved = false;
			Shark cur = sharkQ.front(); sharkQ.pop();

			// �� �� �̵�
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
			// �� ���� �̵� - tmpBoard�� �ƴ� board�� �ٷ� ����
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
		// ��� go away�� �Բ� ���� ����
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

		// ���� �����
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