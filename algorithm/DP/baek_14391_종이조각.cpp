/* https://www.acmicpc.net/problem/14391 */

/*
	종이조각을 왼쪽 위에서부터 숫자를 만들어가며 형태를 만들 때,
	어떤 종이조각들이 만들어지는 과정은 달라도 결과적으로 동일한 모양으로
	사용될 수 있다.
	2 3
	123
	456
	위의 상태에서 1, 2, 4로 나누든 12, 4로 나누든 14, 2로 나누든 남는 종이조각은
	 3
	56 의 모양으로 동일하다는 얘기.
	즉 앞에서 만들어지는 종이 형태를 통해 다음에 계산될 종이의 모양들이 중복될 수 있다.
	즉 DP를 사용할 수 있다.
	종이의 상태를 비트마스크로 표현하여 계산 가능하다.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M, cache[1 << 16], board[4][4];
char c;

int DP(int visited, int sy, int sx) {
	if (sy == N) return 0;
	if (sx == M) return DP(visited, sy + 1, 0);
	if ((1 << (sy * M + sx)) & visited) return DP(visited, sy, sx + 1);

	int &ret = cache[visited];
	if (ret != -1) return ret;

	visited |= (1 << (sy * M + sx));
	int pSum = board[sy][sx], tmpVisited = visited;
	ret = DP(visited, sy, sx + 1) + pSum;

	for (int i = 1; sx + i < M; i++) {
		if (tmpVisited & (1 << (sy * M + sx + i))) break;
		tmpVisited |= (1 << (sy * M + sx + i));
		pSum *= 10;
		pSum += board[sy][sx + i];
		ret = max(ret, DP(tmpVisited, sy, sx + i + 1) + pSum);
	}
	tmpVisited = visited;
	pSum = board[sy][sx];
	for (int i = 1; sy + i < N; i++) {
		if (tmpVisited & (1 << ((sy + i) * M + sx))) break;
		tmpVisited |= (1 << ((sy + i) * M + sx));
		pSum *= 10;
		pSum += board[sy + i][sx];
		ret = max(ret, DP(tmpVisited, sy, sx + 1) + pSum);
	}

	return ret;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> c;
			board[i][j] = c - 48;
		}
		getchar();
	}

	memset(cache, -1, sizeof(cache));

	cout << DP(0, 0, 0) << '\n';
}