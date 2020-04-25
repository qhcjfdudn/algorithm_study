/* https://www.acmicpc.net/problem/12852 */

/*
	DP로 주어진 수 X를 구할 수도 있지만, 범위가 백만의 작은 범위이고,
	BFS를 통해 답을 구하는 것도 가능하기에 BFS를 이용해보자.
	1부터 다음 수로 만들어지는 최소의 경로를 각각의 수에 저장한다.
	이후 X로부터 출력하는 로직을 통해 출력한다.
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