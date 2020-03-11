/* https://www.acmicpc.net/problem/14391 */

/*
	���������� ���� ���������� ���ڸ� ������ ���¸� ���� ��,
	� ������������ ��������� ������ �޶� ��������� ������ �������
	���� �� �ִ�.
	2 3
	123
	456
	���� ���¿��� 1, 2, 4�� ������ 12, 4�� ������ 14, 2�� ������ ���� ����������
	 3
	56 �� ������� �����ϴٴ� ���.
	�� �տ��� ��������� ���� ���¸� ���� ������ ���� ������ ������ �ߺ��� �� �ִ�.
	�� DP�� ����� �� �ִ�.
	������ ���¸� ��Ʈ����ũ�� ǥ���Ͽ� ��� �����ϴ�.
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