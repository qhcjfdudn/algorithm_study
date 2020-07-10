/* https://www.acmicpc.net/problem/2641 */

/*
	다각형의 시작 지점을 고정(왼쪽 맨 위)한 후, 양 방향으로 비교하며 일치하는지 확인한다.
	O(N)으로 풀 수 있을 것.
*/

#include <cstdio>

const int dy[5] = { 0, 0, -1, 0, 1 };
const int dx[5] = { 0, 1, 0, -1, 0 };

int N, M, seq[101][50], ansCnt, ansList[100];
int initIdx[101];

void findInitPos(int idx) {
	int mY = 0, mX = 0, cY = 0, cX = 0;
	for (int i = 0; i < N; i++) {
		cY += dy[seq[idx][i]];
		cX += dx[seq[idx][i]];
		if (cY < mY) {
			mY = cY; mX = cX;
			initIdx[idx] = i + 1;
		}
		else if (cY == mY && cX < mX) {
			mX = cX;
			initIdx[idx] = i + 1;
		}
	}
}

int mapReverseDir(int num) {
	return num < 3 ? num + 2 : num - 2;
}

bool isSamePolygon(int idx) {
	bool up = true;
	for (int i = 0; up && i < N; i++) {
		if (seq[0][(i + initIdx[0]) % N] != seq[idx][(i + initIdx[idx]) % N])
			up = false;
	}
	if (up) return true;

	for (int i = 0; i < N; i++) {
		if (seq[0][(i + initIdx[0]) % N] != mapReverseDir(seq[idx][(N - 1 - i + initIdx[idx]) % N]))
			return false;
	}
	return true;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &seq[0][i]);

	findInitPos(0);

	scanf("%d", &M);
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &seq[i][j]);
		}
		findInitPos(i);
		if (isSamePolygon(i)) {
			ansList[ansCnt] = i;
			ansCnt++;
		}
	}
	printf("%d\n", ansCnt);
	for (int i = 0; i < ansCnt; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", seq[ansList[i]][j]);
		printf("\n");
	}
}