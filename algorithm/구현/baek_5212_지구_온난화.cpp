/* https://www.acmicpc.net/problem/5212 */

/*
	지구 온난화로 인해 바다 주변 육지가 녹아버렸다..
*/

#include <stdio.h>

const int dr[4] = { 0, -1, 0 ,1 };
const int dc[4] = { 1, 0, -1, 0 };

int R, C, cnt_sea[12][12], s_r, s_c, e_r, e_c;
char board[12][13];

void init() {
	scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; ++i)
		scanf("%s", board[i] + 1);

	for (int i = 0; i < R + 1; ++i) board[i][0] = board[i + 1][C + 1] = '.';
	for (int i = 0; i < C + 1; ++i) board[0][i + 1] = board[R + 1][i] = '.';
}
void after_50() {
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			if (board[r][c] == 'X') {
				for (int i = 0; i < 4; ++i) {
					int nr = r + dr[i];
					int nc = c + dc[i];
					cnt_sea[r][c] += (board[nr][nc] == '.');
				}
			}
		}
	}
	for (int r = 1; r <= R; ++r) {
		for (int c = 1; c <= C; ++c) {
			if (cnt_sea[r][c] > 2) {
				board[r][c] = '.';
			}
		}
	}
}
void find_position() {
	for (int i = 1; i <= C && !s_c; ++i)
		for (int j = 1; j <= R && !s_c; ++j)
			if (board[j][i] == 'X') s_c = i;
	for (int i = 1; i <= R && !s_r; ++i)
		for (int j = 1; j <= C && !s_r; ++j)
			if (board[i][j] == 'X') s_r = i;

	for (int i = C; i > 0 && !e_c; --i)
		for (int j = 1; j <= R && !e_c; ++j)
			if (board[j][i] == 'X') e_c = i;
	for (int i = R; i > 0 && !e_r; --i)
		for (int j = 1; j <= C && !e_r; ++j)
			if (board[i][j] == 'X') e_r = i;
}
void print_ans() {
	for (int i = s_r; i <= e_r; ++i) {
		for (int j = s_c; j <= e_c; ++j) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
int main() {
	init();
	after_50();
	find_position();
	print_ans();
}