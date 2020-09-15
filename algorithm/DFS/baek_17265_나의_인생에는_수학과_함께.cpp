/* https://www.acmicpc.net/problem/17265 */

/*
	���ڿ� ������ �ε����� ���ϰ� �ϱ� ����, ���� ũ���� �迭 ������ ����.
	�ְ� ���� ���ϴ� �Լ��� ��Ȱ�� �ϱ� ���� ó������ �� ���� �ּҰ��� ���ϱ� ��,
	������ �迭�� -1�� ���ؼ� minorize�ߴ�.(�� ���¿��� ���� �ִ��� �ּڰ��� �� ���̱� ����)
	�׷��� ���ϱ� ������ �ֱ� ������(��� * ��� = ���, ���� * ���� = ���) ����.
	�ᱹ �Լ��� ���ϴ� ���� �ּڰ����� �ִ������� ���� ���ڸ� �Բ� �����Ͽ���.
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