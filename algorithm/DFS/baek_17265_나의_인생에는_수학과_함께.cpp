/* https://www.acmicpc.net/problem/17265 */

/*
	숫자와 문자의 인덱싱을 편하게 하기 위해, 같은 크기의 배열 공간을 선언.
	최고 값을 구하는 함수를 재활용 하기 위해 처음에는 그 다음 최소값을 구하기 전,
	원래의 배열에 -1을 곱해서 minorize했다.(이 상태에서 구한 최댓값은 최솟값이 될 것이기 때문)
	그런데 곱하기 연산이 있기 때문에(양수 * 양수 = 양수, 음수 * 음수 = 양수) 실패.
	결국 함수에 구하는 값이 최솟값인지 최댓값인지에 대한 인자를 함께 전달하였다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int N, intBoard[5][5], maxV, minV;
char charBoard[5][5];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((i + j) % 2) cin >> charBoard[i][j];
			else cin >> intBoard[i][j];
		}
	}
}

int calc(int num1, char op, int num2) {
	switch (op) {
	case '+': return num1 + num2;
	case '-': return num1 - num2;
	case '*': return num1 * num2;
	default: return num2;
	}
}

int findV(bool findMax, int y, int x, int v, char op) {
	if (y == N || x == N) return findMax ? -INF : INF;
	if (y == N - 1 && x == N - 1) return calc(v, op, intBoard[y][x]);

	int right, down;
	if ((y + x) % 2) {
		right = findV(findMax, y, x + 1, v, charBoard[y][x]);
		down = findV(findMax, y + 1, x, v, charBoard[y][x]);
	}
	else {
		v = calc(v, op, intBoard[y][x]);
		right = findV(findMax, y, x + 1, v, 0);
		down = findV(findMax, y + 1, x, v, 0);
	}
	return findMax ? max(right, down) : min(right, down);
}

void solve() {
	maxV = findV(true, 0, 0, 0, 0);
	minV = findV(false, 0, 0, 0, 0);
	cout << maxV << " " << minV << '\n';
}

int main() {
	init();

	solve();
}