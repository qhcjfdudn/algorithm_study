/* https://www.acmicpc.net/problem/14503 */

/*
	로봇의 입력은 시계방향인데, 실제로 확인해야 하는 방향은 반시계방향.
	결국 매 번 확인하는 반시계방향으로 로봇의 초기 방향 값의 인덱스를 맞춰주는 게 중요.
*/

#include <stdio.h>

const int dr[4] = { 0, 1, 0, -1 };
const int dc[4] = { -1, 0, 1, 0 };

typedef struct {
	int r, c, d;
} Robot;

int N, M, board[52][52];
Robot rbt;

void init() {
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &rbt.r, &rbt.c, &rbt.d);
	rbt.r++, rbt.c++;
	if (rbt.d == 1 || rbt.d == 3) rbt.d = (rbt.d + 2) % 4;

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			scanf("%d", &board[i][j]);

	for (int i = 0; i <= N; ++i) board[i][0] = board[i + 1][M + 1] = 1;
	for (int i = 0; i <= M; ++i) board[0][i + 1] = board[N + 1][i] = 1;
}
int solve() {
	int ret = 0, nr, nc;

	while (1) {
		board[rbt.r][rbt.c] = 2;
		ret++;

		for (int i = 0; i < 4; ++i) {
			nr = rbt.r + dr[(rbt.d + i) % 4];
			nc = rbt.c + dc[(rbt.d + i) % 4];
			if (board[nr][nc] == 0) {
				rbt.r = nr, rbt.c = nc, rbt.d = (rbt.d + i + 1) % 4;
				break;
			}
			if (i == 3) {
				nr = rbt.r + dr[(rbt.d + 1) % 4];
				nc = rbt.c + dc[(rbt.d + 1) % 4];
				if (board[nr][nc] == 2) {
					rbt.r = nr, rbt.c = nc, i = -1;
				}
				else return ret;
			}
		}
	}
}

int main() {
	init();

	printf("%d", solve());
}