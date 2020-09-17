/* https://www.acmicpc.net/problem/1138 */

/*
	�׸����ϰ� ���� Ű�� ���� ������� ��ġ�� �������� ���� �� �ִ�.
*/

#include <iostream>
using namespace std;

int N, rate[10], ans[10];

void init() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> rate[i];
}

void solve() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (ans[j] == 0) {
				if (rate[i] != 0) rate[i]--;
				else {
					ans[j] = i + 1;
					break;
				}
			}
}

void printAns() {
	for (int i = 0; i < N; i++)
		cout << ans[i] << " ";
}

int main() {
	init();
	solve();
	printAns();
}