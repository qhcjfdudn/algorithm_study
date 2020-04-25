/* https://www.acmicpc.net/problem/12852 */

/*
	DP�� �־��� �� X�� ���� ���� ������, ������ �鸸�� ���� �����̰�,
	BFS�� ���� ���� ���ϴ� �͵� �����ϱ⿡ BFS�� �̿��غ���.
	1���� ���� ���� ��������� �ּ��� ��θ� ������ ���� �����Ѵ�.
	���� X�κ��� ����ϴ� ������ ���� ����Ѵ�.
*/

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int > pii;

int X, numList[1000001];

int precalc() {
	int nextList[3];
	queue<pii> Q;
	Q.push({ 1, 0 });

	while (!Q.empty()) {
		pii cur = Q.front(); Q.pop();

		nextList[0] = cur.first + 1;
		nextList[1] = cur.first * 2;
		nextList[2] = cur.first * 3;

		for (int i = 0; i < 3; i++) {
			if (nextList[i] <= X && !numList[nextList[i]]) {
				numList[nextList[i]] = cur.first;
				if (nextList[i] == X) return cur.second + 1;
				Q.push({ nextList[i], cur.second + 1 });
			}
		}
	}
}

void print_solve() {
	while (X) {
		cout << X << " ";
		X = numList[X];
	}
	cout << '\n';
}

int main() {
	cin >> X;

	cout << precalc() << '\n';

	print_solve();
}