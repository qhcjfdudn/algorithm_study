/* https://www.acmicpc.net/problem/2630 */

/*
	색종이를 세는 범위를 분할 정복을 통해 확인 가능.
*/

#include <cstdio>
using namespace std;

struct pii {
	int w, b;
	pii(int _w, int _b) : w(_w), b(_b) {}
	const pii operator + (const pii& rhs) const {
		return pii(w + rhs.w, b + rhs.b);
	}
};

int N, board[128][128];

pii rec(int y, int x, int depth) {
	int len = 1;
	for (int i = 0; i < depth; i++) len <<= 1;

	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
			if (board[y][x] != board[y + i][x + j]) {
				len >>= 1;
				return (rec(y, x, depth - 1) + rec(y + len, x, depth - 1) + rec(y, x + len, depth - 1) + rec(y + len, x + len, depth - 1));
			}

	return pii(board[y][x] == 0, board[y][x] == 1);
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);

	int depth = 0;
	while (N != 1) {
		depth++;
		N >>= 1;
	}

	pii ans = rec(0, 0, depth);
	printf("%d\n%d\n", ans.w, ans.b);
}